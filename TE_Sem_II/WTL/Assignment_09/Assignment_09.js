// Design an application using Angular JS.
// e.g., Design registration (first name, last name, username, password) and
// ogin page using Angular JS.

var app = angular.module('myApp', []);

app.controller('myCtrl', function ($scope) {
    $scope.firstName = "";
    $scope.lastName = "";
    $scope.username = "";
    $scope.password = "";
    $scope.message = "";
    $scope.login = function () {
        if ($scope.username == "admin" && $scope.password == "admin") {
            $scope.message = "Welcome " + $scope.username;
        } else {
            $scope.message = "Invalid username or password";
        }
    };
});
