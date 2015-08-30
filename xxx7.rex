t=1;k=1;
a.=0
do y = 1 to 10 by 5
	t=t+1
	k=k+2
		if k>7 then
	leave  y
end
if i=1 then
 say i
say " k is  after second doto  " k
return k
procedure
do forever
  t =t+1
if t>10 then
	  leave
end
procedure a1 expose a.1 a.2
do for 5
  t =t+1
  say " t in do for 5 " t
end
do for 5
  t =t+1
  say " t ddddddddd in do for 5 " t
end
do for 5
  t =t+1
  say " t ccccccccccccccc in do for 5 " t
end
pull xx;