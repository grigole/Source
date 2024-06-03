show grants;

drop table test.TABLE1;

CREATE TABLE test.TABLE1 
( 
  COLUMN1 VARCHAR(255) NULL
);

SELECT SUBSTRING_INDEX(host, ':', 1) AS host_short,
       GROUP_CONCAT(DISTINCT user) AS users,
       COUNT(*) AS threads
FROM information_schema.processlist
GROUP BY host_short
ORDER BY COUNT(*), host_short;