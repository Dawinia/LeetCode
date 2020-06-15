# Write your MySQL query statement below
select Name Customers from Customers where Id not in (select distinct(CustomerId) from Orders)

select Name as Customers from Customers a left join Orders b on a.Id = b.CustomerId where b.CustomerId is NULL