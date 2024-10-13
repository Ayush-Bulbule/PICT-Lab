### Smart Contract Code

```solidity
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
```

### Explanation of the Code
1. **Struct**:
   - `Student`: A structure that holds student data (ID, name, age).

2. **Array**:
   - `students`: An array to store `Student` objects.

3. **Mapping**:
   - `studentIndex`: A mapping to track the index of each student by their ID, ensuring unique IDs.

4. **Events**:
   - `StudentAdded`: An event emitted whenever a new student is added.

5. **Functions**:
   - `addStudent`: Adds a new student to the array and emits the `StudentAdded` event. It checks for unique IDs.
   - `getStudent`: Retrieves student details using the ID.
   - `fallback`: A fallback function to accept Ether (can be customized further).
   - `getBalance`: Returns the contract’s Ether balance.

### Deploying on Ethereum Test Network
1. **Use Remix IDE**: Open [Remix IDE](https://remix.ethereum.org/).
2. **Create a New File**: Name it `StudentData.sol` and paste the code above.
3. **Compile the Contract**: Click on the "Solidity Compiler" tab and then click "Compile StudentData.sol".
4. **Deploy the Contract**:
   - Go to the "Deploy & Run Transactions" tab.
   - Choose "Injected Web3" to connect your MetaMask wallet (make sure you are on a test network like Ropsten or Rinkeby).
   - Click "Deploy".
5. **Observe Transaction Fee and Gas Values**:
   - After deployment, check the transaction details in MetaMask to see the gas used and the transaction fee.

### Interacting with the Contract
1. **Add a Student**:
   - Use the `addStudent` function to add a student (input ID, name, age).
2. **Get Student Details**:
   - Use the `getStudent` function with the student ID to retrieve details.
3. **Send Ether** (if using the fallback):
   - Send Ether to the contract address to trigger the fallback function and check the contract balance using `getBalance`.

### Important Notes
- **Gas Fees**: Gas fees depend on the network congestion and the complexity of the functions called. You can observe the gas values in the transaction details.
- **Test Ether**: Make sure you have test Ether in your MetaMask wallet for deploying and interacting with the contract.
