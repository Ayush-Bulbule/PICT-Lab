### 05 Assignment

Implement the sample program demonstrating the use of Servlet.
e.g., Create a database table ebookshop (book_id, book_title,book_author,
book_price, quantity) using database like Oracle/MySQL etc. and display
(use SQL select ue ) the table content usin servlet.

#### Common Questions

1. What is Servlet? Explain how a servlet is processed.<br/>
    Ans: Servlet is a Java program that runs on the server side. It is used to handle requests and responses. The main functionality of a servlet is to generate a response based on the request from the client. The servlet is processed by the servlet container. The servlet container is a part of the web server that manages the lifecycle of the servlet. The servlet container loads the servlet class, creates an instance of the servlet, and calls the servlet methods to handle the request and generate the response. The servlet container also manages the threading model for the servlet, so the servlet developer does not have to worry about handling multiple requests concurrently.
    Image: ![Servlet Processing](https://static.javatpoint.com/images/servletlife.jpg)

2. Write a servlet which will accept user name and password in a form,which will compare both in the database to display success or failure.<br/>
    Ans:

    ```java
    import java.io.*;
    import javax.servlet.*;
    import javax.servlet.http.*;
    import java.sql.*;

    public class LoginServlet extends HttpServlet {
        public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from users where username='" + username + "' and password='" + password + "'");
                if (rs.next()) {
                    out.println("Login Successful");
                } else {
                    out.println("Login Failed");
                }
                con.close();
            } catch (Exception e) {
                out.println(e);
            }
        }
    }
    ```

3. Why session management is required in Servlet?<br/>
    Ans: Session management is required in JSP to maintain the user's state, such as login information, shopping cart items, and other user-specific data. Without session management, the server would not be able to maintain the state of the user between requests, and the user would have to re-enter their information each time they make a request.

4. Discuss MVC architecture in details.<br/>
Ans:
    - Model: The model represents the data and the business logic of the application. It is responsible for managing the data, processing the data, and interacting with the database. The model is independent of the view and the controller.
    - View: The view represents the user interface of the application. It is responsible for displaying the data to the user and capturing the user input. The view is independent of the model and the controller.
    - Controller: The controller acts as an intermediary between the model and the view. It is responsible for processing the user input, updating the model, and updating the view. The controller is responsible for handling the user requests and generating the responses.

5. Write a Java Servlet which will display “welcome to Servlet” message.<cbr/>
Ans: Servlet code to display "Welcome to Servlet" message:

    ```java
    import java.io.*;
    import javax.servlet.*;
    import javax.servlet.http.*;

    public class WelcomeServlet extends HttpServlet {
        public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<html><body>");
            out.println("<h1>Welcome to Servlet</h1>");
            out.println("</body></html>");
        }
    }
    ```

6. Create a servlet in java to get user ID and password parameters which are entered in the form of Login.html file.
Ans: Servlet code to get user ID and password parameters:<br/>

    ```java
    import java.io.*;
    import javax.servlet.*;
    import javax.servlet.http.*;

    public class LoginServlet extends HttpServlet {
        public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            String userId = request.getParameter("userId");
            String password = request.getParameter("password");
            out.println("User ID: " + userId + "<br>");
            out.println("Password: " + password + "<br>");
        }
    }
    ```

7. What is thread safety in Servlets? Write a Servlet which will display the count of number of times a client has accessed it.<br/>
    Ans: Thread safety in servlets refers to the ability of a servlet to handle multiple requests concurrently without causing data corruption or inconsistency. A servlet is thread-safe if it can handle multiple requests concurrently without any issues. To make a servlet thread-safe, you can use the synchronized keyword to synchronize access to shared resources or use thread-local variables to store request-specific data.

    Servlet code to display the count of the number of times a client has accessed it:

    ```java
    import java.io.*;
    import javax.servlet.*;
    import javax.servlet.http.*;

    public class CountServlet extends HttpServlet {
        private int count = 0;

        public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            count++;
            out.println("Number of times accessed: " + count);
        }
    }
    ```

8. Explain Session and Cookies in Servlets.<br/>
    Ans: Sessions and cookies are mechanisms in servlets for maintaining state and tracking user interactions. Sessions are server-side data structures that store information about a user's interactions with a web application across multiple requests. Cookies are small pieces of data sent by the server to the client's browser, which are then sent back to the server with subsequent requests.

9. Explain HttpServletRequest and HttpServletResponse with suitable examples. <br/>
    Ans: HttpServletRequest represents the client's request to the server and provides methods to access request parameters, headers, and attributes. HttpServletResponse represents the response from the server to the client and provides methods to set response content, status, and headers.
    Example: Servlet code to get request parameters and set response content type:

    ```java
        @WebServlet("/example")
        public class ExampleServlet extends HttpServlet {
            protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
                // Get request parameters
                String paramValue = request.getParameter("paramName");

                // Set response content type
                response.setContentType("text/html");

                // Get response PrintWriter
                PrintWriter out = response.getWriter();
                out.println("<html><body>");
                out.println("<h1>Hello, " + paramValue + "</h1>");
                out.println("</body></html>");
            }
        }
    ```

10. Explain the following JDBC API components:
    - DriverManager: Manages a list of database drivers. It is used to establish a connection to the database by loading the appropriate driver class.
    - SQLException: Represents an exception thrown by the JDBC API methods when an error occurs during database operations.
    - Connection: Represents a connection to the database. It provides methods for creating statements, managing transactions, and accessing metadata.
    - Statement: Represents an SQL statement that is sent to the database for execution. It can be a simple statement, a prepared statement, or a callable statement.
    - ResultSet: Represents the result of a database query. It provides methods for iterating over the rows, accessing column values, and navigating through the result set.
