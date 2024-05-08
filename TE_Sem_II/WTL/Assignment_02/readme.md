## Assignment 02 - HTML and CSS

### Questions

1. What do you mean by CSS? What are the different ways to create CSS?
    - CSS stands for Cascading Style Sheets. It's used to style the layout and appearance of HTML elements on a webpage. CSS can be created in three main ways: inline, internal, and external. Inline CSS is applied directly to HTML elements using the "style" attribute. Internal CSS is defined within the HTML document using the `<style>` tag in the `<head>` section. External CSS is stored in separate CSS files and linked to HTML documents using the `<link>` tag.

2. What is JSON? Why to use JSON over XML?
    - JSON (JavaScript Object Notation) is a lightweight data-interchange format. It's easy for humans to read and write and easy for machines to parse and generate. JSON is often used for transmitting data between a server and a web application. JSON is preferred over XML due to its simplicity, ease of parsing, and smaller file size, making it more efficient for data exchange over networks, especially in web development.

3. Write at least any five Differences between HTML and HTML5.
    **DOCTYPE Declaration**: HTML5 doesn't require a specific DOCTYPE declaration.
    **New Semantic Elements**: HTML5 introduces new semantic elements like `<header>`, `<footer>`, `<article>`, etc.
    **Audio and Video Support**: HTML5 includes built-in support for audio and video playback.
    **Canvas and SVG**: HTML5 provides the `<canvas>` element for dynamic graphics and supports scalable vector graphics (SVG).
    **Form Enhancements**: HTML5 introduces new form input types like email, url, number, and date.

4. What are the different design issues in web development?
    Web development design issues include accessibility, responsiveness, browser compatibility, usability, performance optimization, security, and user experience (UX) design. Each of these areas requires attention to ensure that websites are inclusive, user-friendly, visually appealing, and performant across different devices and platforms.

5. What is the purpose of HTTP?
    HTTP (Hypertext Transfer Protocol) is a protocol used for transferring hypertext requests and information on the World Wide Web. Its primary purpose is to facilitate communication between web servers and clients, enabling the retrieval and display of web content such as HTML pages, images, videos, and other resources.

6. How does a Web Browser work?
    A web browser retrieves and displays web content by following these steps:
    **Request**: The browser sends an HTTP request to the web server for the desired webpage.
    **Response**: The web server sends back the requested webpage along with any associated resources.
    **Rendering**: The browser processes the received HTML, CSS, and JavaScript to render the webpage.
    **Display**: The rendered webpage is displayed to the user within the browser window.

7. Describe the steps involved when a web browser requests for and obtains a web page from a web server.
    **URL Parsing**: The browser parses the entered URL to extract the protocol, domain, and path.
    **DNS Lookup**: The browser performs a DNS lookup to resolve the domain name to an IP address.
    **HTTP Request**: The browser sends an HTTP request to the web server specified by the resolved IP address.
    **Server Processing**: The web server processes the request, retrieves the requested webpage, and prepares an HTTP response.
    **HTTP Response**: The server sends back the HTTP response containing the requested webpage and associated resources.
    **Rendering**: The browser processes the received content, including HTML, CSS, and JavaScript, to render the webpage.
    **Display**: The rendered webpage is displayed to the user in the browser window.

8. Define the terms i. Website, ii. Web Page, iii. Web Server, iv. URL, and v. Home Page.
    i.**Website**: A collection of related web pages and associated content accessible via a single domain or subdomain.

    ii. **Web Page**: A document displayed in a web browser, typically written in HTML, containing text, images, multimedia, and hyperlinks.

    iii.**Web Server**: Software or hardware that stores, processes, and delivers web content to clients over the internet.

    iv. **URL (Uniform Resource Locator)**: A unique address used to locate resources on the internet, such as web pages, images, or files.

    v. **Home Page**: The main or introductory web page of a website, often serving as the starting point for navigation.

9. Why is HTTP called a stateless protocol? Why is it so?
    HTTP is called a stateless protocol because it does not retain information about previous interactions or requests. Each request from a client to a server is treated as an independent transaction, and the server does not store any session information between requests. This design simplifies implementation, improves scalability, and reduces the burden on servers by eliminating the need to maintain client state.

10. Discuss any three HTTP commands.
    **GET**: Requests data from a specified resource.
    **POST**: Submits data to be processed to a specified resource.
    **PUT**: Uploads a representation of the specified resource.
    These commands are part of the HTTP request methods used by clients to communicate with web servers.

11. Discuss the idea of HTML tags with an example.
    HTML tags are used to define the structure and content of web documents. They are enclosed in angle brackets and typically come in pairs: an opening tag and a closing tag. For example, <p> is an opening tag used to define a paragraph, and </p> is a closing tag to denote the end of the paragraph.

12. Describe any five HTML tags.
    `<div>`: Defines a division or section in an HTML document.
    `<img>`: Embeds an image in an HTML document.
    `<a>`: Creates a hyperlink to another webpage or resource.
    `<ul>`: Defines an unordered list.
    `<table>`: Defines a table structure for displaying data.
    These tags are essential for structuring and formatting content in HTML documents.

13. Investigate how you can set up your own website. What are the requirements for the same?
    To set up a website, you'll need a domain name, web hosting, and website content. Choose a domain name that reflects your brand or business, purchase web hosting from a hosting provider, and create your website content using HTML, CSS, and possibly JavaScript. Upload your files to the web server provided by your hosting provider and configure DNS settings to point your domain to your server's IP address. Additionally, consider security measures such as SSL certificates and regularly update your website content to keep it fresh and engaging.

14. Create a web page that displays your own details in about 100 words, and includes your photographs.

    ```html
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>My Details</title>
    </head>
    <body>
        <h1>About Me</h1>
        <img src="your_photo.jpg" alt="Your Name">
        <p>
            Hello! My name is [Your Name]. I am passionate about [mention your interests or field of study].
            This website is a platform for me to share my thoughts, experiences, and projects with the world.
            Feel free to explore and get in touch!
        </p>
    </body>
    </html>
    ```

15. Find out major differences between the two web browsers- Internet Explorer and Mozilla Firefox
    Internet Explorer and Mozilla Firefox differ in terms of rendering engine, performance, security, features, and compatibility. Firefox generally offers better standards compliance, faster performance, stronger security features, and a wider range of extensions compared to Internet Explorer. Additionally, Firefox is known for its open-source nature and community-driven development model, while Internet Explorer has been criticized for its slower adoption of web standards and security vulnerabilities.

16. What is HTML? Do all HTML tags have end tags?
    HTML (Hypertext Markup Language) is a markup language used to create the structure and content of web pages. It consists of a set of elements or tags that define the different parts of a webpage, such as headings, paragraphs, links, images, and forms. Not all HTML tags have end tags. Some tags, like `<img>`, `<br>`, and `<input>`, are self-closing and do not require separate closing tags.

17. What is the difference between HTML elements and tags?
    HTML elements are the building blocks of HTML documents, consisting of an opening tag, content, and optional closing tag. Tags, on the other hand, are the markup symbols used to define HTML elements. For example, <p> is the opening tag of a paragraph element, and </p> is its corresponding closing tag. Together, the opening and closing tags define the boundaries of the paragraph element, enclosing its content.

18. What is a style sheet? How do you create multi-color text on a web page using CSS?
    A style sheet is a document or file that contains style rules or instructions for formatting the presentation of HTML elements on a web page. CSS (Cascading Style Sheets) is the most common type of style sheet used in web development. To create multi-color text on a web page using CSS, you can use the color property to specify different colors for different parts of the text. Here's an example:

        ```css
            p {
                color: red; /* Set the color of the text to red */
            }

            span {
                color: blue; /* Set the color of the text within the span element to blue */
            }
        ```

        ```html
        <p>This is a paragraph with <span>multi-color text</span>.</p>
        ```

19. What is the difference between the progress and meter tags?
    progress: The `<progress>` tag is used to represent the progress of a task, such as file upload or download, with a visual indicator.
    meter: The `<meter>` tag is used to measure data within a known range and display it as a gauge, such as disk usage or battery level.

20. What are the new `<input>` types for form validation in HTML?
    HTML5 introduced several new input types for form validation, including:
    email: Validates input as an email address.
    url: Validates input as a URL.
    number: Validates input as a numeric value.
    date: Validates input as a date.
    tel: Validates input as a telephone number.
These input types help improve user experience by providing built-in validation and input controls.

21. Create a web page for an Admission form using all tags in HTML.
    Ans: Web page for an Admission form using HTML tags:

    ```html
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Admission Form</title>
        </head>
        <body>
            <h1>Admission Form</h1>
            <form>
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required><br><br>
                <label for="email">Email:</label>
                <input type="email" id="email" name="email" required><br><br>
                <label for="dob">Date of Birth:</label>
                <input type="date" id="dob" name="dob" required><br><br>
                <label for="course">Select Course:</label>
                <select id="course" name="course">
                    <option value="engineering">Engineering</option>
                    <option value="medical">Medical</option>
                    <option value="management">Management</option>
                </select><br><br>
                <label for="comments">Comments:</label><br>
                <textarea id="comments" name="comments" rows="4" cols="50"></textarea><br><br>
                <input type="submit" value="Submit">
            </form>
        </body>
        </html>
    ```

    This web page includes various HTML tags such as `<form>`, `<input>`, `<label>`, `<select>`, `<option>`, `<textarea>`, `<datalist>`, and `<submit>` to create an admission form.

22. What is the use of static & dynamic web page? Enlist applications of static & dynamic web pages.
    Ans:
        - Static Web Page: A static web page displays the same content to all users and does not change unless the developer manually updates it. Static web pages are suitable for content that doesn't need frequent updates, such as company information, product descriptions, and contact details.
        - Dynamic Web Page: A dynamic web page generates content dynamically based on user interactions, input, or database queries. Dynamic web pages can personalize content for each user, support interactive features like forms and search functionality, and provide real-time updates. They are commonly used in e-commerce platforms, social media sites, web applications, and content management systems (CMS).
        Applications:
        Static Web Page: Company websites, portfolios, informational websites.
        Dynamic Web Page: E-commerce platforms, social networking sites, web applications, online banking portals.
