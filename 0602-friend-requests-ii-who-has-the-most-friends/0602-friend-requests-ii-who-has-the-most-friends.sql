# Write your MySQL query statement below

with cte as 
(SELECT requester_id as id, accepter_id from RequestAccepted
UNION 
select accepter_id as id, requester_id from RequestAccepted)

select id, count(distinct accepter_id) as num
from cte
group by id
order by num desc
limit 1;