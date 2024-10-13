// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    mapping(address => uint256) private balances;

    event Deposited(address indexed user, uint256 amount);
    event Withdrawn(address indexed user, uint256 amount);

    constructor() {
        owner = msg.sender; // Set the contract creator as the owner
    }

    // Deposit money into the bank account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than zero.");
        
        balances[msg.sender] += msg.value; // Increase the balance of the sender
        emit Deposited(msg.sender, msg.value); // Emit deposit event
    }

    // Withdraw money from the bank account
    function withdraw(uint256 amount) public {
        require(amount > 0, "Withdrawal amount must be greater than zero.");
        require(balances[msg.sender] >= amount, "Insufficient balance.");

        balances[msg.sender] -= amount; // Decrease the balance of the sender
        payable(msg.sender).transfer(amount); // Transfer the amount to the sender
        emit Withdrawn(msg.sender, amount); // Emit withdrawal event
    }

    // Show the balance of the bank account
    function showBalance() public view returns (uint256) {
        return balances[msg.sender]; // Return the balance of the sender
    }
}
