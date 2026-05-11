SELECT email AS 'Email' FROM PERSON
GROUP BY email
HAVING COUNT(email) > 1;
