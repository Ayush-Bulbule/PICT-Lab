// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint256 id;
        string name;
        uint256 age;
    }

    Student[] public students; // Array to store students
    mapping(uint256 => uint256) public studentIndex; // Mapping to track student index by ID

    event StudentAdded(uint256 id, string name, uint256 age); // Event for new student added

    // Function to add a new student
    function addStudent(uint256 _id, string memory _name, uint256 _age) public {
        require(studentIndex[_id] == 0, "Student ID already exists."); // Ensure unique ID

        students.push(Student(_id, _name, _age)); // Add student to array
        studentIndex[_id] = students.length; // Store index
        emit StudentAdded(_id, _name, _age); // Emit event
    }

    // Function to get student details by ID
    function getStudent(uint256 _id) public view returns (uint256, string memory, uint256) {
        require(studentIndex[_id] != 0, "Student not found."); // Ensure student exists

        Student memory student = students[studentIndex[_id] - 1]; // Retrieve student
        return (student.id, student.name, student.age);
    }

    // Fallback function to accept Ether
    fallback() external payable {
        // Functionality for receiving Ether can be added here
    }
    
    // Function to retrieve contract balance
    function getBalance() public view returns (uint256) {
        return address(this).balance; // Return contract balance
    }
}