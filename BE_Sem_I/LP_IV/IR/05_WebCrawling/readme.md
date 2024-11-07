### **Assignment 5: Web Crawling**

#### **Problem Statement**
Write a simple program to implement a web crawler that can extract URLs from a given webpage and follow those URLs to extract additional links recursively.

#### **Objective**
- Understand the concept of web crawling and its application in retrieving data from the web.
- Learn how to handle HTTP requests, parse HTML content, and follow links using a crawler.

#### **Outcome**
- Implement a basic web crawler that can navigate through websites by extracting and following links.
- Gain experience in web scraping and data extraction techniques.

#### **Software and Hardware Used**
- **OS**: 64-bit Ubuntu
- **RAM**: 8GB (Recommended)
- **Tools**: Python
- **Libraries**: `requests`, `BeautifulSoup` (for web scraping)

#### **References**
1. "Web Scraping with Python" by Ryan Mitchell  
2. "Python Web Scraping" by Katharine Jarmul, Richard Lawson  
3. BeautifulSoup Documentation: [Link](https://www.crummy.com/software/BeautifulSoup/bs4/doc/)

#### **Theory**
**Web Crawling**:  
A web crawler (or spider) is a program that automatically browses the web, fetches web pages, and extracts relevant data. It’s widely used in search engines to index web pages. 

1. **HTTP Requests**: A web crawler sends HTTP requests to web servers to fetch the content of webpages.
2. **HTML Parsing**: The content fetched is usually in HTML, and it needs to be parsed to extract meaningful data, such as links, text, or images.
3. **Following Links**: A crawler extracts links from the current page and then follows those links to gather more pages recursively.
4. **Data Storage**: The fetched data (links, text, etc.) can be stored in a database or file for future use.

#### **Algorithm**
1. Start with a given URL (seed URL).
2. Send an HTTP request to the URL to retrieve the HTML content.
3. Parse the HTML content to extract all anchor tags (`<a>`) and their `href` attributes.
4. Add extracted links to a list of URLs to visit.
5. Repeat the process for each URL in the list.
6. Optionally, store the crawled pages or links in a file or database.
7. Implement limits such as depth or the number of pages to crawl to avoid infinite loops or excessive requests.

#### **Test Cases**
1. **Input**: Start URL = "https://example.com"
   **Output**: Extracted links from "https://example.com" (URLs from `<a href>` tags).

2. **Input**: Start URL = "https://example.com/firstpage"
   **Output**: Extracted links from "https://example.com/firstpage" and subsequent pages if following links are found.

#### **Conclusion/Analysis**
The web crawler was implemented successfully, demonstrating the ability to extract links from webpages and follow them recursively. The crawler can be extended to perform more complex tasks, such as data extraction or multi-threading for faster performance. Proper handling of HTTP errors, rate limiting, and ensuring polite crawling (using `robots.txt`) should be considered for real-world applications.

#### **Review Questions**
### **Review Questions for Web Crawling**

1. **What is a Web Crawler?**
   - Define a web crawler and explain its main purpose.

2. **What is the difference between a web crawler and a web scraper?**
   - Describe the distinctions between web crawlers and scrapers, and when each is used.

3. **How does a web crawler follow links on a webpage?**
   - Explain the process of link extraction and crawling in a recursive manner.

4. **What is the role of the `robots.txt` file in web crawling?**
   - Discuss the purpose of `robots.txt` and how it affects the crawling process.

5. **What are the common challenges faced when implementing a web crawler?**
   - Mention challenges like handling rate limits, dealing with dynamic content, avoiding infinite loops, and managing large volumes of data.

6. **What is HTTP status code 404, and how should a web crawler handle it?**
   - Define HTTP status code 404 and explain how a crawler should handle this situation.

7. **What are some best practices to follow when crawling a website?**
   - Discuss best practices like obeying robots.txt, respecting rate limits, and ensuring you don't overload a website's server.

8. **What is the difference between synchronous and asynchronous crawling?**
   - Explain the difference and how asynchronous crawling can improve the speed of a crawler.

9. **How can a web crawler be optimized to handle large websites?**
   - Mention techniques for optimizing a crawler for scalability, such as multi-threading, data storage options, and efficient parsing methods.

10. **Why is it important to parse and sanitize the data retrieved by a web crawler?**
   - Explain why parsing and sanitizing data are important to prevent errors and ensure meaningful extraction from the crawled pages.

