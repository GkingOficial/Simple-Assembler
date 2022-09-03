main: 

		add $s1 $zero $zero # (comentario)

		bne $t0 $zero exit
		addi $t0 $zero 6
		addi $t1 $zero 12
		# (comentario)
		sw $t0, 23($t1)
j volta
		addi $t2 $zero 3
		and $s1, $s2, $zero
		slt $s1, $s2, $zero

volta:  beq $t0 $zero exit
				sub $s0 $s0 $t1

				lw $t0, -42($t1)

				add $t1 $t1 $t2
				jr $ra
				addi $t0 $t0 -1
				xor $t2, $t3, $t4
	exit:
	jal volta
	or $s4, $s5, $s6