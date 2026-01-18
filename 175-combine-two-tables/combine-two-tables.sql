# Write your MySQL query statement below

select P.firstName,  P.lastName, A.city, A.state 
From Person as  P Left JOIN Address as A 
on P.personId = A.personId 