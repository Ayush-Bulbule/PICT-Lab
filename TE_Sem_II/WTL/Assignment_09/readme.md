## Assignment 09 - Angular JS

AngularJS is a JavaScript-based open-source front-end web application framework mainly maintained by Google and by a community of individuals and corporations to address many of the challenges encountered in developing single-page applications. It aims to simplify both the development and the testing of such applications by providing a framework for client-side model–view–controller (MVC) and model–view–viewmodel (MVVM) architectures, along with components commonly used in rich Internet applications.

### Questions

1. Write a node How am angularJS application can be developed using MVC architecture?
Ans: An AngularJS application can be developed using MVC architecture by dividing the application into three main components: Model, View, and Controller.
    - Model: The model represents the data of the application. It is responsible for managing the data and business logic of the application.
    - View: The view represents the user interface of the application. It is responsible for displaying the data to the user and capturing user input.
    - Controller: The controller acts as an intermediary between the model and the view. It is responsible for handling user input, updating the model, and updating the view.

2. What are Directives in AngularJS?
Ans: Directives in AngularJS are markers on a DOM element that tell AngularJS's HTML compiler to attach a specified behavior to that DOM element or even transform the DOM element and its children.
Examples of directives are ng-app, ng-model, ng-bind, ng-repeat, etc.

3. How AngularJS expressions are different from the JavaScript expressions?
Ans: AngularJS expressions are different from JavaScript expressions in the following ways:
    - AngularJS expressions are evaluated in the context of AngularJS, while JavaScript expressions are evaluated in the context of JavaScript.
    - AngularJS expressions can be used in HTML templates, while JavaScript expressions cannot be used in HTML templates.
    - AngularJS expressions can be used to bind data to HTML elements, while JavaScript expressions cannot be used to bind data to HTML elements.
    - AngularJS expressions can be used to create dynamic content in HTML templates, while JavaScript expressions cannot be used to create dynamic content in HTML templates.

4. What are Expressions in AngularJS?
Ans: Expressions in AngularJS are used to bind data to HTML elements. They are written inside double curly braces {{ }} and are evaluated by AngularJS to generate dynamic content in HTML templates.

5. What are Filters in AngularJS?
Ans: Filters in AngularJS are used to format the data before displaying it to the user. They can be used to format numbers, dates, strings, arrays, objects, etc. Filters are applied to expressions using the pipe character (|) followed by the filter name.

6. What is Angular Prefixes $ and $$?
Ans: Angular prefixes $ and $$ are used to denote AngularJS built-in services and private services, respectively. The $ prefix is used for public services provided by AngularJS, while the $$ prefix is used for private services that are not meant to be accessed directly by developers.

7. What is Global API?
Ans: The Global API in AngularJS provides access to various global services and functions that can be used throughout the application. Some of the commonly used global services and functions are $rootScope, $http, $location, $timeout, $interval, etc.

8. When dependent modules of a module are loaded?
Ans: The dependent modules of a module are loaded before the module itself is loaded. AngularJS uses a dependency injection mechanism to load the dependencies of a module before the module is instantiated.

9. How angular modules load the dependencies?
Ans: Angular modules load the dependencies using the dependency injection mechanism. When a module is instantiated, AngularJS looks up the dependencies of the module and loads them before instantiating the module.

10. What is core module in AngularJS?
Ans: The core module in AngularJS is the ng module, which is the core module of AngularJS. It provides the basic functionality of AngularJS, such as data binding, directives, filters, services, etc.

11. What components can be defined within AngularJS modules?
Ans: Components that can be defined within AngularJS modules are controllers, services, filters, directives, and templates. These components can be defined within AngularJS modules to organize the code and provide modularity to the application.

12. What is the size of angular.js file?
Ans: The size of the angular.js file is around 150 KB when minified and gzipped. The size of the angular.js file may vary depending on the version of AngularJS and the modules included in the file.

13. What browsers AngularJS support?
Ans: AngularJS supports all modern browsers, including Chrome, Firefox, Safari, Opera, and Internet Explorer 9 and above. AngularJS uses the latest web standards and features to provide a consistent experience across different browsers.

14. Is AngularJS a library, framework, plugin or a browser extension?
Ans: AngularJS is a framework for building dynamic web applications. It provides a set of tools and services that can be used to develop single-page applications and rich Internet applications. AngularJS is not a library, plugin, or browser extension.

15. How to use jQuery with AngularJS?
Ans: jQuery can be used with AngularJS by including the jQuery library in the HTML file and using it in AngularJS controllers, directives, or services. However, it is recommended to use AngularJS's built-in features and services instead of jQuery to avoid conflicts and improve performance.

16. Does AngularJS has dependency on jQuery?
Ans: AngularJS does not have a hard dependency on jQuery, but it can be used with jQuery if needed. AngularJS provides its own set of tools and services for DOM manipulation, event handling, and AJAX requests, so jQuery is not required to build AngularJS applications.

17. How AngularJS is different from other JavaScript Framework?
Ans: AngularJS is different from other JavaScript frameworks in the following ways:
    - AngularJS is an open-source front-end web application framework maintained by Google, while other frameworks may be maintained by different organizations or individuals.
    - AngularJS uses a two-way data binding mechanism to synchronize the model and the view, while other frameworks may use different data binding mechanisms.
    - AngularJS provides a set of built-in directives, filters, services, and modules to simplify the development of web applications, while other frameworks may require additional libraries or plugins to achieve similar functionality.
    - AngularJS uses dependency injection to manage the dependencies of components, while other frameworks may use different dependency management mechanisms.

18. What are the advantages of AngularJS?
Ans: The advantages of AngularJS are as follows:
    - Two-way data binding: AngularJS provides two-way data binding between the model and the view, which simplifies the development of dynamic web applications.
    - Directives: AngularJS provides a set of built-in directives that can be used to extend HTML and create reusable components.
    - Dependency injection: AngularJS uses dependency injection to manage the dependencies of components, which makes the code more modular and testable.
    - Services: AngularJS provides a set of built-in services that can be used to perform common tasks, such as HTTP requests, routing, and animation.
    - Testing: AngularJS provides support for unit testing and end-to-end testing, which makes it easier to test AngularJS applications.

19. Why to use AngularJS?
Ans: AngularJS is used to develop dynamic web applications that require rich user interfaces and interactive features. It provides a set of tools and services that can be used to build single-page applications, rich Internet applications, and mobile applications. AngularJS is popular among developers because of its two-way data binding, dependency injection, and modular architecture.

20. What are different ways to invoke a directive?
Ans: Directives in AngularJS can be invoked in different ways:
    - Element: Directives can be invoked as elements in the HTML code, such as <my-directive></my-directive>.
    - Attribute: Directives can be invoked as attributes in the HTML code, such as <div my-directive></div>.
    - Class: Directives can be invoked as classes in the HTML code, such as <div class="my-directive"></div>.
    - Comment: Directives can be invoked as comments in the HTML code, such as <!-- directive: my-directive -->.
