## Assignment 07 - PHP

Build a dynamic web application using PHP and MySQL. Create database tables in MySQL and create connection with PHP.Create the add, update, delete and retrieve functions in the PHP web app interactin with M S L database

### Questions

1. What these tags specify in PHP : <?php and ?>
Ans: These tags are used to specify the start and end of PHP code. The PHP code is written between these tags.

2. Can we run PHP from HTML file? If yes, how?
Ans: Yes, we can run PHP from HTML file. We can run PHP from HTML file by saving the file with .php extension.

3. Why PHP is known as scripting language?
Ans: PHP is known as scripting language because it is a server side language and it is used to write scripts that are executed on the server.

4. Write a program in PHP to calculate Square Root of a number?
Ans: Program to calculate Square Root of a number is as follows:

    ```php
        <?php
        $num = 16;
        $sqrt = sqrt($num);
        echo "Square root of $num is $sqrt";
        ?>
    ```

5. How can we create links in PHP pages?
Ans: We can create links in PHP pages using the following code:

    ```php
        <?php
        echo "<a href='page2.php'>Go to Page 2</a>";
        ?>
    ```

6. What is the function of “foreach”construct in PHP?
Ans: The function of “foreach” construct in PHP is to loop through each key/value pair in an array.

7. What is the purpose of “nl2br “string function?
Ans: The purpose of “nl2br” string function is to insert HTML line breaks before all newlines in a string.

8. Write the name of PHP functions that can be used to build a function that accepts any number ofarguments?
Ans: The name of PHP functions that can be used to build a function that accepts any number of arguments are func_get_args() and func_num_args().

9. Whatis the difference between include and require?
Ans: The difference between include and require is that if the file is not found, include will produce a warning and the script will continue to run, while require will produce a fatal error and the script will stop running.

10. Differences between GET and POST methods?
Ans: The differences between GET and POST methods are as follows:
    - GET method is used to send data to the server in the URL, while POST method is used to send data to the server in the body of the request.
    - GET method is not secure as the data is visible in the URL, while POST method is secure as the data is not visible in the URL.
    - GET method has a limit on the amount of data that can be sent, while POST method has no limit on the amount of data that can be sent.
    - POST method is used when the data is sensitive and should not be visible in the URL, while GET method is used when the data is not sensitive and can be visible in the URL.
    - POST method is used to send data to the server to be processed, while GET method is used to retrieve data from the server.

11. What do you mean by Server Side Scripting?
Ans: Server Side Scripting is a type of scripting that is executed on the server side. It is used to generate dynamic web pages by processing data on the server and sending the output to the client.

12. Explain all possible types of scope of variable?
Ans: The possible types of scope of variable are as follows:
    - Local Scope: A variable declared inside a function has local scope and can only be accessed within that function.
    - Global Scope: A variable declared outside a function has global scope and can be accessed anywhere in the script.
    - Static Scope: A static variable retains its value between function calls and has static scope.
    - Parameter Scope: A variable passed as a parameter to a function has parameter scope and can only be accessed within that function.

13. Explain with example the use of substring function?
Ans: The substring function is used to extract a part of a string. It takes two arguments, the string and the starting position of the substring. For example:

    ```php
        <?php
        $str = "Hello World";
        $sub = substr($str, 6);
        echo $sub;
        ?>
    ```

14. Write a program in HTML (Web-Page)having a form with firstname, lastname and a submit button. On clicking the button form validation should work (Use Javascript for that) and data entryshould be saved in a database (PHP code needed, for insertion of data from “form” to database). Form should be styled using CSS. (Use any mode-inline, internal or external)?
Ans: Program

    ```html
        <!DOCTYPE html>
        <html>
        <head>
            <title>Form Validation</title>
            <style>
                input[type=text] {
                    width: 100%;
                    padding: 12px 20px;
                    margin: 8px 0;
                    display: inline-block;
                    border: 1px solid #ccc;
                    box-sizing: border-box;
                }
                input[type=submit] {
                    width: 100%;
                    background-color: #4CAF50;
                    color: white;
                    padding: 14px 20px;
                    margin: 8px 0;
                    border: none;
                    cursor: pointer;
                }
                input[type=submit]:hover {
                    background-color: #45a049;
                }
            </style>
        </head>
        <body>
            <form action="insert.php" method="post" onsubmit="return validateForm()">
                <label for="fname">First Name:</label>
                <input type="text" id="fname" name="fname" required>
                <label for="lname">Last Name:</label>
                <input type="text" id="lname" name="lname" required>
                <input type="submit" value="Submit">
            </form>
            <script>
                function validateForm() {
                    var fname = document.forms["myForm"]["fname"].value;
                    var lname = document.forms["myForm"]["lname"].value;
                    if (fname == "" || lname == "") {
                        alert("Name must be filled out");
                        return false;
                    }
                }
            </script>
        </body>
        </html>
    ```

    PHP Code

    ```php
        <?php
        $servername = "localhost";
        $username = "username";
        $password = "password";
        $dbname = "myDB";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $fname = $_POST['fname'];
        $lname = $_POST['lname'];

        $sql = "INSERT INTO MyGuests (firstname, lastname)
        VALUES ('$fname', '$lname')";

        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();

        ?>

    ```

15. What do you understand about Numeric array, Associative array and Multidimensional
array?
Ans: Numeric Array: A numeric array is an array in which the keys are numeric values. The values in a numeric array are accessed using numeric indices.

16. What is the use of strlen() and strpos() functions?
Ans: The strlen() function is used to get the length of a string. The strpos() function is used to find the position of the first occurrence of a substring in a string.

17. Why we use $_REQUEST variable?Write a note on various library functions available in
PHP?
Ans: The $_REQUEST variable is used to collect data from HTML forms. It is a superglobal variable that can be used to collect data from both the GET and POST methods.

18. Whatisthe function name in PHP, usedto delete an element from an array?
Ans: The function name in PHP used to delete an element from an array is unset().

19. Write the PHP code for fetching the data from a database to a webpage?
Ans:  PHP code for fetching the data from a database to a webpage is as follows:

    ```php
        <?php
        $servername = "localhost";
        $username = "username";
        $password = "password";
        $dbname = "myDB";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT id, firstname, lastname FROM MyGuests";

        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            // output data of each row
            while($row = $result->fetch_assoc()) {
                echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br>";
            }
        } else {
            echo "0 results";
        }
        $conn->close();

        ?>

    ```
