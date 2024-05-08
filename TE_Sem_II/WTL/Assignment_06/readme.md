## Assignment 06 - JSP

JSP (JavaServer Pages) is a technology that helps software developers create dynamically generated web pages based on HTML, XML, or other document types. Released in 1999 by Sun Microsystems, JSP is similar to PHP and ASP, but it uses the Java programming language.

### Questions

1. What are the various element of JSP page? <br/>
Ans: The various elements of a JSP page are:
    - Directives: Directives are used to provide instructions to the JSP container. There are three types of directives: page directive, include directive, and taglib directive.
    - Declarations: Declarations are used to declare variables and methods in a JSP page. The variables and methods declared in a declaration are available to the entire JSP page.
    - Scriptlets: Scriptlets are used to write Java code in a JSP page. The Java code written in a scriptlet is executed when the JSP page is processed by the JSP container.
    - Expressions: Expressions are used to display the output of a Java expression in a JSP page. The output of the expression is converted to a string and included in the response sent to the client.
    - Actions: Actions are used to perform specific tasks in a JSP page. There are several built-in actions available in JSP, such as include, forward, useBean, and setProperty.

2. Why session management is required in JSP? <br/>
Ans: Session management is required in JSP to maintain the state of the user across multiple requests. A session is a way to store information about a user between requests. It allows the server to associate a set of data with a particular user, so that the user can be identified across multiple requests.

3. Write a JSP scriptlet for displaying even numbers between 1 to 50and also its JSTL version. <br/>
Ans:
    - JSP scriptlet for displaying even numbers between 1 to 50:

        ```jsp
        <%@ page import="java.util.*" %>
        <%
            for (int i = 1; i <= 50; i++) {
                if (i % 2 == 0) {
                    out.println(i + "<br>");
                }
            }
        %>
        ```

        ```jsp
        <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
        <c:forEach var="i" begin="1" end="50" step="1">
            <c:if test="${i % 2 == 0}">
                ${i}<br>
            </c:if>
        </c:forEach>
        ```

4. List and elaborate any five JSP implicit objects with examples. <br/>
Ans:
    - request: The request object represents the HTTP request made by the client. It provides methods to access the request parameters, headers, and other information.
    - response: The response object represents the HTTP response sent by the server. It provides methods to set the response headers, cookies, and other information.
    - session: The session object represents the user's session with the server. It provides methods to store and retrieve session attributes.
    - application: The application object represents the web application running on the server. It provides methods to store and retrieve application-wide attributes.
    - out: The out object represents the output stream used to send the response to the client. It provides methods to write text and HTML content to the response.

5. Write JSP code to accept product details and store in database table. If the product is already inserted, display the appropriate message to insert another product. (Assume suitable table structures). <br/>
Ans:
    - JSP code to accept product details and store in database table:

        ```jsp
        <%@ page import="java.sql.*" %>
        <%
            String productId = request.getParameter("productId");
            String productName = request.getParameter("productName");
            String productPrice = request.getParameter("productPrice");
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from products where productId='" + productId + "'");
                if (rs.next()) {
                    out.println("Product already exists");
                } else {
                    stmt.executeUpdate("insert into products values('" + productId + "','" + productName + "','" + productPrice + "')");
                    out.println("Product inserted successfully");
                }
                con.close();
            } catch (Exception e) {
                out.println(e);
            }
        %>
        ```

6. Write advantages of JSP over Servlets? Also explain life cycle of aJSP. <br/>
Ans: Advantages of JSP over Servlets:
    - JSP allows the separation of presentation logic from business logic, which makes the code easier to maintain and update.
    - JSP provides a higher level of abstraction, which makes it easier to develop web applications.
    - JSP allows the use of custom tags and tag libraries, which makes it easier to reuse code and reduce duplication.
    - JSP provides built-in support for session management, error handling, and other common web application features.

    Life cycle of a JSP:
    - Translation: The JSP container translates the JSP page into a servlet class.
    - Compilation: The JSP container compiles the servlet class into a Java class file.
    - Initialization: The JSP container loads the servlet class and creates an instance of the servlet.
    - Execution: The JSP container calls the service() method of the servlet to process the request and generate the response.
    - Destruction: The JSP container destroys the servlet instance when the JSP page is no longer needed.

7. List and elaborate any five JSP actions with example. <br/>
Ans: JSP actions are special XML tags that are used to perform specific tasks in a JSP page. Some common JSP actions are:
    - include: The include action is used to include the content of another resource in the current JSP page. For example, `<jsp:include page="header.jsp" />` includes the content of the header.jsp file in the current JSP page.
    - forward: The forward action is used to forward the request to another resource. For example, `<jsp:forward page="error.jsp" />` forwards the request to the error.jsp file.
    - useBean: The useBean action is used to create or retrieve a JavaBean object in a JSP page. For example, `<jsp:useBean id="user" class="com.example.User" scope="session" />` creates a User object and stores it in the session scope with the id "user".
    - setProperty: The setProperty action is used to set the properties of a JavaBean object in a JSP page. For example, `<jsp:setProperty name="user" property="name" value="John Doe" />` sets the "name" property of the User object to "John Doe".
    - includeAction: The includeAction action is used to include the content of another resource in the current JSP page at runtime. For example, `<jsp:includeAction page="/header.jsp" />` includes the content of the header.jsp file in the current JSP page at runtime.

8. Explain HTTP request and response messages used in JSP. <br/>
Ans: There are two types of messages used in JSP:
    - HTTP request: An HTTP request is a message sent by the client to the server to request a resource. It contains information about the resource being requested, such as the URL, method, headers, and body. The HTTP request is processed by the server, which generates an HTTP response to send back to the client.
    - HTTP response: An HTTP response is a message sent by the server to the client in response to an HTTP request. It contains information about the response, such as the status code, headers, and body. The HTTP response is processed by the client, which displays the response to the user.

9. Create a JSP page to search a student details from database by studentId. (Assume suitable table structure). <br/>
Ans: JSP code to search a student details from database by studentId:
        ```jsp
        <%@ page import="java.sql.*" %>
        <%
            String studentId = request.getParameter("studentId");
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from students where studentId='" + studentId + "'");
                if (rs.next()) {
                    out.println("Student ID: " + rs.getString("studentId") + "<br>");
                    out.println("Student Name: " + rs.getString("studentName") + "<br>");
                    out.println("Student Age: " + rs.getInt("studentAge") + "<br>");
                } else {
                    out.println("Student not found");
                }
                con.close();
            } catch (Exception e) {
                out.println(e);
            }
        %>
        ```

10. What are JSP actions? Explain error handling in JSP using JSP actions with example. <br/>
Ans: JSP actions are special XML tags that are used to perform specific tasks in a JSP page. Some common JSP actions are:
    - include: The include action is used to include the content of another resource in the current JSP page. For example, `<jsp:include page="header.jsp" />` includes the content of the header.jsp file in the current JSP page.
    - forward: The forward action is used to forward the request to another resource. For example, `<jsp:forward page="error.jsp" />` forwards the request to the error.jsp file.
    - useBean: The useBean action is used to create or retrieve a JavaBean object in a JSP page. For example, `<jsp:useBean id="user" class="com.example.User" scope="session" />` creates a User object and stores it in the session scope with the id "user".
    - setProperty: The setProperty action is used to set the properties of a JavaBean object in a JSP page. For example, `<jsp:setProperty name="user" property="name" value="John Doe" />` sets the "name" property of the User object to "John Doe".
    - includeAction: The includeAction action is used to include the content of another resource in the current JSP page at runtime. For example, `<jsp:includeAction page="/header.jsp" />` includes the content of the header.jsp file in the current JSP page at runtime.

    Error handling in JSP using JSP actions:
        ```jsp
        <%@ page isErrorPage="true" %>
        <html>
        <head>
            <title>Error Page</title>
        </head>
        <body>
            <h1>Error Details</h1>
            <p>Exception: <%= exception %></p>
            <p>Message: <%= exception.getMessage() %></p>
        </body>
        </html>
        ```

11. What is use of isThreadSafe in JSP? Also Explain Single Thread Model in JSP. <br/>
Ans: The isThreadSafe attribute in JSP is used to specify whether the JSP page is thread-safe or not. If the isThreadSafe attribute is set to true, the JSP page is thread-safe, which means that multiple threads can access the JSP page concurrently without any issues. If the isThreadSafe attribute is set to false, the JSP page is not thread-safe, which means that only one thread can access the JSP page at a time.

12. Explain different session management mechanism in JSP.
Ans: The different session management mechanisms in JSP are:
    - URL rewriting: In URL rewriting, the session ID is appended to the URL as a query parameter. This allows the server to associate the session with the client across multiple requests.
    - Cookies: In cookies-based session management, the server sends a cookie containing the session ID to the client. The client includes the cookie in subsequent requests, allowing the server to associate the session with the client.
    - Hidden form fields: In hidden form fields-based session management, the session ID is stored in a hidden form field on the client side. The client includes the session ID in subsequent form submissions, allowing the server to associate the session with the client.
    - HttpSession: The HttpSession object is a built-in session management mechanism provided by JSP. It allows the server to store and retrieve session attributes associated with a particular client.

13. Write a jsp code which adds the student education details in a database through Java bean. <br/>
Ans: JSP code to add student education details in a database through JavaBean:
        ```jsp
        <%@ page import="java.sql.*" %>
        <jsp:useBean id="student" class="com.example.Student" scope="session" />
        <jsp:setProperty name="student" property="*" />
        <%
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
                PreparedStatement stmt = con.prepareStatement("insert into students values(?,?,?,?)");
                stmt.setString(1, student.getStudentId());
                stmt.setString(2, student.getStudentName());
                stmt.setInt(3, student.getStudentAge());
                stmt.setString(4, student.getEducationDetails());
                stmt.executeUpdate();
                out.println("Student added successfully");
                con.close();
            } catch (Exception e) {
                out.println(e);
            }
        %>
        ```

14. What are the usage of JSP Directives and JSP Actions. <br/>
Ans: The usage of JSP directives and JSP actions are:
    - JSP directives: JSP directives are used to provide instructions to the JSP container. There are three types of directives: page directive, include directive, and taglib directive. The page directive is used to specify the attributes of the JSP page, such as the content type and language. The include directive is used to include the content of another resource in the JSP page. The taglib directive is used to define custom tag libraries in the JSP page.
    - JSP actions: JSP actions are special XML tags that are used to perform specific tasks in a JSP page. There are several built-in actions available in JSP, such as include, forward, useBean, and setProperty. JSP actions allow the developer to perform common tasks, such as including content from another resource, forwarding the request to another resource, creating JavaBean objects, and setting the properties of JavaBean objects.

15. Write the different usage of JSP action tags and directives. <br/>
Ans: The different usages of JSP action tags and directives are:
    - JSP action tags: JSP action tags are used to perform specific tasks in a JSP page. There are several built-in actions available in JSP, such as include, forward, useBean, and setProperty. JSP action tags allow the developer to perform common tasks, such as including content from another resource, forwarding the request to another resource, creating JavaBean objects, and setting the properties of JavaBean objects. Eg. `<jsp:include page="header.jsp" />`

    - JSP directives: JSP directives are used to provide instructions to the JSP container. There are three types of directives: page directive, include directive, and taglib directive. The page directive is used to specify the attributes of the JSP page, such as the content type and language. The include directive is used to include the content of another resource in the JSP page. The taglib directive is used to define custom tag libraries in the JSP page. Eg. `<%@ page import="java.util.*" %>`

16. Create simple JSP pages which will explain use implicit session object of JSP. <br/>
Ans: JSP code to explain the use of the implicit session object:
        ```jsp
        <%
            session.setAttribute("username", "john.doe");
            String username = (String) session.getAttribute("username");
            out.println("Welcome, " + username);
        %>
        ```

17. Write JSP code for accepting product-id from user. Verify if product already exists the <br/>
Ans: JSP code to accept product-id from the user and verify if the product already exists:
        ```jsp
        <%@ page import="java.sql.*" %>
        <%
            String productId = request.getParameter("productId");
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from products where productId='" + productId + "'");
                if (rs.next()) {
                    out.println("Product already exists");
                } else {
                    out.println("Product does not exist");
                }
                con.close();
            } catch (Exception e) {
                out.println(e);
            }
        %>
        ```
18. What is difference between include action and include directive in JSP? <br/>
Ans: The difference between include action and include directive in JSP is:
    - Include action: The include action is a JSP action tag that is used to include the content of another resource in the current JSP page at runtime. The include action is processed by the JSP container at runtime, and the included content is merged with the current JSP page before it is sent to the client.
    - Include directive: The include directive is a JSP directive that is used to include the content of another resource in the current JSP page at translation time. The include directive is processed by the JSP container at translation time, and the included content is merged with the current JSP page before it is compiled into a servlet class.

19. How do you define application wide error page in JSP? <br/>
Ans: To define an application-wide error page in JSP, you can use the isErrorPage attribute of the page directive. For example:
        ```jsp
        <%@ page isErrorPage="true" %>
        <html>
        <head>
            <title>Error Page</title>
        </head>
        <body>
            <h1>Error Details</h1>
            <p>Exception: <%= exception %></p>
            <p>Message: <%= exception.getMessage() %></p>
        </body>
        </html>
        ```

20. What is the use of JSP useBean action? <br/>
Ans: The useBean action is used to create or retrieve a JavaBean object in a JSP page. It allows the developer to use JavaBean objects in a JSP page without having to write Java code. The useBean action creates an instance of a JavaBean class and stores it in a specified scope, such as request, session, or application. The useBean action can also be used to retrieve an existing JavaBean object from the specified scope.
