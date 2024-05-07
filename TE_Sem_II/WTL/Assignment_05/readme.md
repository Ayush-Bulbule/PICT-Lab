### 05 Assignment

Implement the sample program demonstrating the use of Servlet.
e.g., Create a database table ebookshop (book_id, book_title,book_author,
book_price, quantity) using database like Oracle/MySQL etc. and display
(use SQL select ue ) the table content usin servlet.

#### Common Questions

1. What is Servlet? Explain how a servlet is processed.
Ans: Servlet is a Java program that runs on the server side. It is used to handle requests and responses. The main functionality of a servlet is to generate a response based on the request from the client. The servlet is processed by the servlet container. The servlet container is a part of the web server that manages the lifecycle of the servlet. The servlet container loads the servlet class, creates an instance of the servlet, and calls the servlet methods to handle the request and generate the response. The servlet container also manages the threading model for the servlet, so the servlet developer does not have to worry about handling multiple requests concurrently.

2. Write a servlet which will accept user name and password in a form,which will compare both in the database to display success or failure.
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

3. Why session management is required in Servlet?
Ans: Session management is required in JSP to maintain the user's state, such as login information, shopping cart items, and other user-specific data. Without session management, the server would not be able to maintain the state of the user between requests, and the user would have to re-enter their information each time they make a request.

4. Discuss MVC architecture in details.
Ans:
    - Model: The model represents the data and the business logic of the application. It is responsible for managing the data, processing the data, and interacting with the database. The model is independent of the view and the controller.
    - View: The view represents the user interface of the application. It is responsible for displaying the data to the user and capturing the user input. The view is independent of the model and the controller.
    - Controller: The controller acts as an intermediary between the model and the view. It is responsible for processing the user input, updating the model, and updating the view. The controller is responsible for handling the user requests and generating the responses.

5. Write a Java Servlet which will display “welcome to Servlet” message.
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
Ans: Servlet code to get user ID and password parameters:

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

17. What is thread safety in Servlets? Write a Servlet which will display the count of number of times a client has accessed it.

20 Explain Session and Cookies in Servlets.
22 Explain HttpServletRequest and HttpServletResponse with suitable examples.
display details. If not insert details into product table. (Assume suitable table structure)
29 Explain the following JDBC API components:
DriverManager 2. SQLException 3.Connection 4.Statement 5.ResultSet
