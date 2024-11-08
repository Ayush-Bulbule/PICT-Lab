import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse
import time
from typing import Set, Optional

class WebCrawler:
    def __init__(self, max_depth: int = 2, delay: float = 1.0):
        """
        Initialize the web crawler with configurations.
        
        Args:
            max_depth: Maximum depth to crawl (default: 2)
            delay: Delay between requests in seconds (default: 1.0)
        """
        self.max_depth = max_depth
        self.delay = delay
        self.visited_urls: Set[str] = set()
        
    def is_valid_url(self, url: str) -> bool:
        """Check if the URL is valid and has http/https scheme."""
        try:
            result = urlparse(url)
            return all([result.scheme, result.netloc]) and result.scheme in ['http', 'https']
        except ValueError:
            return False
    
    def get_page_content(self, url: str) -> Optional[str]:
        """
        Fetch the content of a webpage.
        
        Args:
            url: The URL to fetch
            
        Returns:
            The page content as string or None if failed
        """
        try:
            headers = {
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
            }
            response = requests.get(url, headers=headers, timeout=10)
            response.raise_for_status()
            return response.text
        except (requests.RequestException, Exception) as e:
            print(f"Error fetching {url}: {str(e)}")
            return None
    
    def extract_links(self, url: str, html_content: str) -> set:
        """
        Extract all links from the HTML content.
        
        Args:
            url: Base URL for resolving relative links
            html_content: HTML content to parse
            
        Returns:
            Set of absolute URLs found in the page
        """
        links = set()
        soup = BeautifulSoup(html_content, 'html.parser')
        
        for anchor in soup.find_all('a'):
            href = anchor.get('href')
            if href:
                absolute_url = urljoin(url, href)
                if self.is_valid_url(absolute_url):
                    links.add(absolute_url)
        return links
    
    def crawl(self, start_url: str):
        """
        Start crawling from the given URL.
        
        Args:
            start_url: The URL to start crawling from
        """
        def _crawl_recursive(url: str, depth: int = 0):
            # Check depth limit and if URL was already visited
            if depth >= self.max_depth or url in self.visited_urls:
                return
            
            # Mark URL as visited
            self.visited_urls.add(url)
            print(f"\nCrawling: {url} (Depth: {depth})")
            
            # Get page content
            content = self.get_page_content(url)
            if not content:
                return
            
            # Extract and process links
            links = self.extract_links(url, content)
            print(f"Found {len(links)} links")
            
            # Respect crawl delay
            time.sleep(self.delay)
            
            # Recursively crawl extracted links
            for link in links:
                if link not in self.visited_urls:
                    _crawl_recursive(link, depth + 1)
        
        if not self.is_valid_url(start_url):
            print("Invalid start URL")
            return
        
        print(f"Starting crawl from: {start_url}")
        print(f"Max depth: {self.max_depth}")
        _crawl_recursive(start_url)
        print("\nCrawl completed!")
        print(f"Total pages crawled: {len(self.visited_urls)}")

# Example usage
if __name__ == "__main__":
    # Create crawler instance with max depth of 2 and 1 second delay between requests
    crawler = WebCrawler(max_depth=2, delay=1.0)
    
    # Start crawling from a seed URL
    seed_url = "https://example.com"
    crawler.crawl(seed_url)