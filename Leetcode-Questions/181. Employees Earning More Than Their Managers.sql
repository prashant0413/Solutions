--Write your MySQL query statement below

-- ANSWER 1
SELECT name AS 'Employee' FROM Employee e
WHERE salary > (
    SELECT salary FROM Employee
    WHERE id = e.managerId
);

-- ANSWER 2
SELECT e.name AS 'Employee' FROM Employee e
INNER JOIN
Employee m on e.managerId = m.id
WHERE e.salary > m.salary;
