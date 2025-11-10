// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

// contract BankAccount{

//     // mapping(address => uint) public balances;
//     address public accHolder;
//     uint balance = 0;

//     constructor() {
//         accHolder = msg.sender;

//     }

//     function deposit() public payable{
//         // balances[msg.sender] += msg.value;
//         require(msg.value > 0, "Deposit amount should be greater than 0");
//         require(msg.sender == accHolder, "You are not the account owner");

//         balance += msg.value;
//     }

//     function withDraw(uint _amount) public{
//         // require(balances[msg.sender] >= _amount, "Insufficient funds");
//         // balances[msg.sender] -= _amount;
//         // payable(msg.sender).transfer(_amount);

//         require(balance > _amount, "Insufficient Balance in account!");
//         require(msg.sender == accHolder, "You are not the account owner");
//         balance-=_amount;
//         payable(msg.sender).transfer(_amount);

//     }

//     function showBalance() public view returns (uint){
//         // return balances[msg.sender];
//         return balance;
//     }

// }

contract BankAccount2{

    mapping(address => uint) public balances;

    function deposit() public payable {
        balances[msg.sender] += msg.value;

    }

    function withDraw(uint _amt) public {
        require(balances[msg.sender] >= _amt, "Insufficient funds in your account");
        balances[msg.sender] -= _amt;
        payable(msg.sender).transfer(_amt);

    }

    function showBalance() public view returns(uint){
        return balances[msg.sender];
    }

}