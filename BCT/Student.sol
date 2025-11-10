// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{

    struct Student{
        uint id;
        string name;
        uint age;
    }

    Student[] public students;

    function addStudent(uint _id, string memory _name, uint _age) public {
        students.push(Student(_id, _name, _age));
    }

    function getStudentById(uint _id) public view returns (uint, string memory, uint){
        for(uint i=0;i<students.length;i++){
            if(students[i].id == _id){
                return(students[i].id, students[i].name, students[i].age);
            }
        }
        revert("Student with given ID not found");

    }

    function removeStudentById(uint _id) public {
        for(uint i=0;i<students.length;i++){
            if(students[i].id == _id){
                students[i] = students[students.length -1];
                students.pop();
                return;
            }
        }
        revert("Student with given ID not found");

    } 

    function getAllStudents() public view returns (Student[] memory){
        return students;
    }

    function editStudentById(uint _id,string memory _name,  uint _age ) public{
        for(uint i=0;i<students.length;i++){
            if(students[i].id == _id){
                students[i].name = _name;
                students[i].age = _age;
                return;
            }
        }
        revert("Student with given ID not found");
    } 

    // Fallback function - called when no function matches
    fallback() external payable {}

    receive() external payable {}


}
