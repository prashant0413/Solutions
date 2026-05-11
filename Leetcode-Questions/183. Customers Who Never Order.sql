SELECT name AS 'Customer' FROM Customers
WHERE id NOT IN (
  SELECT customerId FROM Orders
);
