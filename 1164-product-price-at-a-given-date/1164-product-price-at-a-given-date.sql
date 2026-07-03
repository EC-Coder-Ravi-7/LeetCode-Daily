# Write your MySQL query statement below
select p.product_id, p.new_price as price
from Products p
JOIN (
    select product_id, max(change_date) as latest_date from Products
    where change_date <= '2019-08-16'
    group by product_id
) latest
ON p.product_id = latest.product_id
and p.change_date = latest.latest_date

UNION

select distinct product_id, 10 as price
from products
where product_id not in (
    select product_id
    from products
    where change_date <= '2019-08-16'
);