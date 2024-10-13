Below is a simple smart contract written in Solidity for a bank account that allows customers to deposit money, withdraw money, and check their balance. This contract can be deployed on a test network like Ropsten or Rinkeby using Remix IDE.

### Smart Contract Code

```solidity
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
```

### Explanation of the Code
1. **State Variables**:
   - `owner`: Stores the address of the contract owner.
   - `balances`: A mapping that tracks the balances of each user.

2. **Events**:
   - `Deposited`: Emitted when a deposit is made.
   - `Withdrawn`: Emitted when a withdrawal is made.

3. **Constructor**:
   - Initializes the `owner` variable to the address that deploys the contract.

4. **Deposit Function**:
   - Accepts Ether deposits and updates the balance of the sender.
   - Emits a `Deposited` event.

5. **Withdraw Function**:
   - Allows users to withdraw their balance.
   - Checks that the user has enough balance and updates the state accordingly.
   - Emits a `Withdrawn` event.

6. **Show Balance Function**:
   - Returns the balance of the calling user.

### Deploying on a Test Network
1. **Use Remix IDE**: Open [Remix IDE](https://remix.ethereum.org/).
2. **Create a New File**: Name it `BankAccount.sol` and paste the code above.
3. **Compile the Contract**: Click on the "Solidity Compiler" tab and then click "Compile BankAccount.sol".
4. **Deploy the Contract**:
   - Go to the "Deploy & Run Transactions" tab.
   - Choose "Injected Web3" to connect MetaMask (ensure you’re on a test network).
   - Click "Deploy".
5. **Interact with the Contract**:
   - Use the deployed contract interface to call `deposit`, `withdraw`, and `showBalance`.

### Important Notes
- Ensure you have test Ether in your MetaMask wallet for transactions.
- Always test smart contracts thoroughly on test networks before deploying them to the mainnet. 

By following these steps, you will have a functioning smart contract for a bank account that supports depositing, withdrawing, and checking balances!