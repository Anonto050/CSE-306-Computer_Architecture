addi $t2, $zero, 2 
add $t1, $t2, $t0
addi $t0, $t1, -1
srl $t4, $t2, 1
sll $t3, $t1, 2
ori $t2, $zero, -4
or $t0, $t2, $t0
and $t4, $t1, $t3
nor $t3, $t3, $t4
L1: sub $t1, $t1, $t0
subi $t4, $zero, 2
andi $t2, $t3, 6
end:
