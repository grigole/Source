SELECT SUBSTRING_INDEX(host, ':', 1) AS host_short,
       GROUP_CONCAT(DISTINCT user) AS users,
       COUNT(*) AS threads
FROM information_schema.processlist
GROUP BY host_short
ORDER BY COUNT(*), host_short;

select * from mysql.user;

SELECT *
FROM information_schema.processlist;

show create user 'grigole'@'localhost';

show create database test;

create database greg;

drop database greg;

show databases;

show engines;

show create table mysql.db;
