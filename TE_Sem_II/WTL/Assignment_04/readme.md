## Assignment No 04 - JavaScript

JavaScript is a versatile programming language that is widely used for creating interactive and dynamic web applications. It is a client-side scripting language that runs in the browser and allows developers to manipulate the content, structure, and behavior of web pages. JavaScript can be used to add interactivity, validate user input, create animations, and communicate with servers to fetch or send data.

### Questions

1. What is JavaScript? How is it different from Java?<br/>
    Ans: JavaScript is a high-level, interpreted programming language primarily used for client-side web development. It is designed to add interactivity and dynamic behavior to web pages, allowing developers to create interactive user interfaces, validate user input, and manipulate the content of web pages. JavaScript is executed in the browser environment and can interact with the Document Object Model (DOM) to modify the structure and appearance of web pages.

    Java, on the other hand, is a general-purpose, object-oriented programming language that can be used for a wide range of applications, including web development, mobile app development, and enterprise software development. Java is compiled into bytecode and runs on the Java Virtual Machine (JVM), making it platform-independent and suitable for building large-scale applications.

    The key differences between JavaScript and Java include:
    - JavaScript is a client-side scripting language, while Java is a general-purpose programming language.
    - JavaScript is interpreted at runtime by the browser, while Java is compiled into bytecode and executed on the JVM.
    - JavaScript is primarily used for web development, while Java is used for a variety of applications, including web, mobile, and enterprise development.
    - JavaScript interacts with the DOM to manipulate web pages, while Java is used for building standalone applications and server-side services.

2. What are the key features of JavaScript?<br/>
    Ans: JavaScript offers several key features that make it a popular choice for web development:
    - Interactivity: JavaScript allows developers to create interactive user interfaces and dynamic web applications that respond to user actions.
    - DOM Manipulation: JavaScript can interact with the Document Object Model (DOM) to modify the structure, content, and styling of web pages.
    - Event Handling: JavaScript enables developers to respond to user events, such as clicks, keypresses, and mouse movements, to trigger specific actions.
    - Asynchronous Programming: JavaScript supports asynchronous programming through callbacks, promises, and async/await, allowing developers to handle tasks that require waiting for responses from servers or other operations.
    - Cross-platform Compatibility: JavaScript runs on all major web browsers and platforms, making it a versatile language for building web applications that work across different devices and environments.
    - Extensibility: JavaScript can be extended with libraries and frameworks, such as React, Angular, and Vue.js, to simplify development and enhance functionality.
    - Server-side Development: JavaScript can also be used for server-side development with Node.js, allowing developers to build full-stack applications using a single language.

3. What is the Document Object Model (DOM) in JavaScript?<br/>
    Ans: The Document Object Model (DOM) is a programming interface that represents the structure of an HTML or XML document as a tree of objects. In the context of JavaScript, the DOM provides a way to interact with the elements, attributes, and content of a web page dynamically. Developers can use JavaScript to access, modify, and update the DOM elements to create interactive and dynamic web applications.

    The DOM consists of a hierarchy of nodes, where each node represents an element, attribute, or text content of the document. JavaScript can manipulate the DOM by selecting elements, changing their attributes or content, adding new elements, and responding to user events. By interacting with the DOM, developers can create rich user interfaces, validate user input, and update the content of web pages in real-time.

4. What are the different ways to include JavaScript in an HTML document?<br/>
    Ans: There are several ways to include JavaScript code in an HTML document:
    - Inline Script: JavaScript code can be included directly within the HTML document using the `<script>` tag with the `type="text/javascript"` attribute. For example:

        ```html
        <script type="text/javascript">
            alert("Hello, World!");
        </script>
        ```

    - External Script: JavaScript code can be placed in an external file with a `.js` extension and included in the HTML document using the `<script>` tag with the `src` attribute. For example:

        ```html
        <script src="script.js"></script>
        ```

    - Event Handlers: JavaScript code can be attached to HTML elements as event handlers using attributes like `onclick`, `onmouseover`, or `onsubmit`. For example:

        ```html
        <button onclick="alert('Button Clicked!')">Click Me</button>
        ```

    - External Libraries: JavaScript libraries and frameworks, such as jQuery, React, or Angular, can be included in an HTML document by linking to their CDN or local files. For example:

        ```html
        <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
        ```

5. What is the difference between `==` and `===` operators in JavaScript?<br/>
    Ans: In JavaScript, the `==` and `===` operators are used for comparison, but they have different behaviors:
    - `==` (Equality Operator): The `==` operator compares two values for equality after performing type coercion. It converts the operands to the same type before comparing them. For example, `1 == '1'` would return `true` because the string `'1'` is converted to a number before comparison.
    - `===` (Strict Equality Operator): The `===` operator compares two values for equality without performing type coercion. It checks both the value and the type of the operands. For example, `1 === '1'` would return `false` because the operands are of different types.

    In general, it is recommended to use the `===` operator for strict equality comparisons to avoid unexpected behavior due to type coercion. The `==` operator should be used with caution, as it may lead to unintended results when comparing values of different types.

6. What are JavaScript closures? Provide an example.<br/>
    Ans: JavaScript closures are a powerful feature that allows functions to retain access to variables from their containing scope even after the scope has been destroyed. A closure is created when a function is defined within another function and has access to the outer function's variables. Closures are commonly used to create private variables, encapsulate functionality, and maintain state across multiple function calls.

    Here's an example of a closure in JavaScript:

    ```javascript
    function outerFunction() {
        let outerVariable = 'I am from the outer function';

        function innerFunction() {
            console.log(outerVariable);
        }

        return innerFunction;
    }

    const closure = outerFunction();
    closure(); // Output: I am from the outer function
    ```

    In this example, the `innerFunction` has access to the `outerVariable` defined in the `outerFunction` even after the `outerFunction` has finished executing. The `closure` function retains a reference to the `outerVariable` and can access it when called.

7. What is event delegation in JavaScript? Why is it useful?<br/>
    Ans: Event delegation is a technique in JavaScript where a single event listener is attached to a parent element to handle events that occur on its child elements. Instead of attaching event listeners to each individual child element, event delegation allows developers to listen for events at a higher level in the DOM hierarchy and handle them based on the target element that triggered the event.

    Event delegation is useful for several reasons:
    - Reduced Memory Usage: By attaching a single event listener to a parent element, developers can avoid creating multiple event listeners for each child element, reducing memory usage and improving performance.
    - Dynamic Content: Event delegation works well with dynamically generated content or elements added to the DOM after the initial page load. New elements can be handled by the existing event listener without the need to attach new listeners.
    - Simplified Code: Event delegation simplifies the code by centralizing event handling logic in one place, making it easier to manage and maintain event-related functionality.

8. What is the difference between `null` and `undefined` in JavaScript?<br/>
    Ans: In JavaScript, `null` and `undefined` are two distinct primitive values that represent different states:
    - `null`: The `null` value represents the intentional absence of any object value. It is used to indicate that a variable or property has no value or has been explicitly set to `null` by the programmer.
    - `undefined`: The `undefined` value represents the absence of a value or the uninitialized state of a variable. It is the default value assigned to variables that have not been initialized or do not have a value.

    The key differences between `null` and `undefined` are:
    - `null` is a value that can be assigned to a variable to indicate the absence of an object value, while `undefined` is a default value assigned to uninitialized variables.
    - `null` is a primitive value, while `undefined` is a type and a value in JavaScript.
    - `null` is explicitly assigned by the programmer, while `undefined` is automatically assigned by JavaScript.

9. What is the difference between `let`, `const`, and `var` in JavaScript?<br/>
    Ans: In JavaScript, `let`, `const`, and `var` are used to declare variables, but they have different scoping rules and behaviors:
        - `var`: The `var` keyword is function-scoped, meaning that variables declared with `var` are accessible within the function in which they are defined. Variables declared with `var` are hoisted to the top of their containing function or global scope.
        - `let`: The `let` keyword is block-scoped, meaning that variables declared with `let` are accessible only within the block in which they are defined. Variables declared with `let` are not hoisted to the top of their containing block.
        - `const`: The `const` keyword is block-scoped like `let`, but it creates a constant variable whose value cannot be reassigned. The value of a `const` variable is fixed once assigned and cannot be changed.

10. What are arrow functions in JavaScript? Provide an example.<br/>
    Ans: Arrow functions are a concise way to write functions in JavaScript using the `=>` syntax. They provide a more compact and readable syntax compared to traditional function expressions. Arrow functions do not have their own `this`, `arguments`, `super`, or `new.target` bindings, making them suitable for use in callback functions, event handlers, and other scenarios where lexical scoping is desired.

    Here's an example of an arrow function in JavaScript:

    ```javascript
    // Traditional function expression
    const add = function(a, b) {
        return a + b;
    };

    // Arrow function
    const add = (a, b) => a + b;
    ```

    In this example, the arrow function `add` takes two parameters `a` and `b` and returns their sum. Arrow functions can be used for single-line expressions without the need for curly braces or an explicit `return` statement.

11. What is the purpose of the `this` keyword in JavaScript?<br/>
    Ans: In JavaScript, the `this` keyword refers to the context in which a function is executed. The value of `this` is determined by how a function is called and can vary based on the invocation context. The `this` keyword is commonly used in object-oriented programming to refer to the current object instance within a method.

    The value of `this` can be:
    - Global Context: When used in the global scope or outside of any function, `this` refers to the global object (`window` in browsers, `global` in Node.js).
    - Object Context: When used within a method of an object, `this` refers to the object that contains the method.
    - Constructor Context: When used within a constructor function, `this` refers to the newly created object instance.
    - Event Handler Context: When used in an event handler, `this` refers to the element that triggered the event.

12. What is the difference between synchronous and asynchronous JavaScript?<br/>
    Ans: Synchronous and asynchronous JavaScript refer to the way in which code execution is handled:
    - Synchronous JavaScript: In synchronous code execution, statements are executed one after the other in a sequential manner. Each statement must complete before the next one can begin. Synchronous code blocks the execution thread until a task is completed, which can lead to performance issues and unresponsive user interfaces.
    - Asynchronous JavaScript: In asynchronous code execution, tasks are executed concurrently without blocking the main thread. Asynchronous operations, such as fetching data from a server or waiting for a user input, are handled using callbacks, promises, or async/await syntax. Asynchronous code allows non-blocking operations, enabling better performance and responsiveness in web applications.

    Asynchronous JavaScript is commonly used for tasks that involve waiting for external resources, such as network requests, file I/O, or user interactions. By handling these tasks asynchronously, developers can prevent the main thread from being blocked and provide a smoother user experience.

13. What are promises in JavaScript? How do they work?<br/>
    Ans: Promises are a built-in feature in JavaScript that represents the eventual completion or failure of an asynchronous operation and its resulting value. Promises simplify asynchronous programming by providing a way to handle asynchronous tasks in a more readable and manageable manner. A promise can be in one of three states: pending, fulfilled, or rejected.

    Promises work by chaining together asynchronous operations using the `then` and `catch` methods. The `then` method is used to handle the successful completion of a promise, while the `catch` method is used to handle errors or rejections. Promises can be created using the `Promise` constructor and resolved using the `resolve` and `reject` functions.

    Here's an example of using promises in JavaScript:

    ```javascript
    const fetchData = () => {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                const data = { message: 'Data fetched successfully' };
                resolve(data);
            }, 2000);
        });
    };

    fetchData()
        .then((data) => {
            console.log(data.message);
        })
        .catch((error) => {
            console.error(error);
        });
    ```

    In this example, the `fetchData` function returns a promise that resolves after a delay of 2 seconds. The `then` method is used to handle the successful completion of the promise, while the `catch` method is used to handle any errors that occur during the asynchronous operation.

14. What is the event loop in JavaScript? How does it work?<br/>
    Ans: The event loop is a fundamental concept in JavaScript that handles the execution of code in a non-blocking and asynchronous manner. The event loop continuously checks the call stack for tasks to execute and the callback queue for tasks to process. It ensures that the main thread is not blocked by long-running tasks and allows for the handling of asynchronous operations.

    The event loop works by following a cycle of checking the call stack, executing tasks, and processing callbacks:
    - The call stack is a data structure that tracks the execution of synchronous code. When a function is called, it is added to the call stack, and when it completes, it is removed from the stack.
    - Asynchronous tasks, such as timers, network requests, or event handlers, are handled by the event loop. When an asynchronous task completes, its callback is added to the callback queue.
    - The event loop continuously checks the call stack and the callback queue. If the call stack is empty, the event loop moves tasks from the callback queue to the call stack for execution.

    By managing the execution of code in a non-blocking manner, the event loop allows JavaScript to handle asynchronous operations efficiently and maintain responsiveness in web applications.

15. What is the purpose of the `fetch` API in JavaScript? How does it work?<br/>
    Ans: The `fetch` API is a modern JavaScript feature that provides an interface for fetching resources (such as JSON data, images, or files) from a server using the HTTP protocol. The `fetch` API is built on top of promises and provides a more flexible and powerful way to make network requests compared to traditional methods like XMLHttpRequest.

16. What is JSON? How is it related to JavaScript?<br/>
    Ans: JSON (JavaScript Object Notation) is a lightweight data interchange format that is easy for humans to read and write and easy for machines to parse and generate. JSON is based on a subset of the JavaScript programming language and is commonly used for transmitting data between a server and a web application.

    JSON data is represented as key-value pairs and supports various data types, including strings, numbers, booleans, arrays, and objects. JSON is often used in web development for sending and receiving data from APIs, storing configuration settings, and exchanging data between different systems.

17. What are JavaScript modules? How do they work?<br/>
    Ans: JavaScript modules are a way to organize and encapsulate code into reusable units that can be imported and exported between different files or modules. Modules help to break down large codebases into smaller, more manageable pieces and promote code reuse, maintainability, and scalability.

    JavaScript modules work by using the `export` and `import` statements to define and consume module dependencies. The `export` statement is used to expose functions, variables, or classes from a module, while the `import` statement is used to import these exported entities into another module.

18. What is the difference between `setTimeout` and `setInterval` in JavaScript?<br/>
    Ans: In JavaScript, `setTimeout` and `setInterval` are used to execute code after a specified delay, but they have different behaviors:
    - `setTimeout`: The `setTimeout` function is used to execute a function or code snippet after a specified delay (in milliseconds). It runs the code once after the delay and does not repeat.
    - `setInterval`: The `setInterval` function is used to execute a function or code snippet repeatedly at a specified interval (in milliseconds). It runs the code continuously at the specified interval until it is cleared using `clearInterval`.

    While `setTimeout` is used for executing code once after a delay, `setInterval` is used for executing code repeatedly at regular intervals. Both functions are commonly used for implementing animations, timers, and periodic tasks in JavaScript.

19. What is the purpose of the `localStorage` and `sessionStorage` objects in JavaScript?<br/>
    Ans: The `localStorage` and `sessionStorage` objects are part of the Web Storage API in JavaScript and provide a way to store key-value pairs locally in the browser. Both objects offer a simple and persistent storage mechanism for storing data on the client-side, but they have different lifetimes and scopes:
    - `localStorage`: The `localStorage` object stores data with no expiration date, meaning that the data persists even after the browser is closed and reopened. The data stored in `localStorage` is available across browser sessions and tabs.
    - `sessionStorage`: The `sessionStorage` object stores data for the duration of the page session, which lasts as long as the browser tab is open. The data stored in `sessionStorage` is available only within the same tab or window and is cleared when the tab is closed.

20. What are the different ways to handle errors in JavaScript?<br/>
    Ans: There are several ways to handle errors in JavaScript to prevent runtime exceptions and improve the robustness of code:
    - `try...catch`: The `try...catch` statement is used to catch and handle exceptions that occur within a block of code. The `try` block contains the code that may throw an error, and the `catch` block handles the error if one occurs.
    - `throw`: The `throw` statement is used to create custom errors and throw exceptions in JavaScript. Developers can use the `throw` statement to raise errors based on specific conditions or validation checks.
    - `Error` Object: The `Error` object is a built-in object in JavaScript that represents an error condition. Developers can create instances of the `Error` object to provide detailed information about errors, such as error messages and stack traces.
    - `Promise.catch`: When working with promises, the `catch` method can be used to handle errors that occur during asynchronous operations. The `catch` method is used to handle rejected promises and perform error handling logic.
