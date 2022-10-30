# Kuena Mahase 202000020 
# number: 59598785/69426317
#email: kuenamahase1101@gmail.com
#CS2520 Assignment 1

.data

.text
main:
	jal reverse                   #calling the reverse funtion
	
	li $v0,1			#output the reversed interger		
	move $a0,$t2
	syscall
	
	li $v0,10			#end of main program
	syscall

	reverse:			#reverse function
		li $a1,345		#a1 = 345 
		li $t1,10		#t1 = 10
		li $t2,0		#t2 = 0


	loop1:
		beq $a1,$zero,Exit	#if a1 = 0, branch to exit
		div $a1,$t1		# a1/t1 (finding modulus)
		mfhi $t3		#move remainder to t3
		mul $t4,$t2,$t1		# t4 = t2 * t1
		add $t2,$t4,$t3		# t2 = t4 + t3
		div $a1,$t1		#a1/t1
		mflo $a1		#move quotient to a1
	
		j loop1		#looping through loop1
		jr $ra

Exit:
	li $v0,1    #after looping through reverse funtion, output the accumulated value of the reverse value
	move $a0,$t2
	syscall
	
	li $v0,10 	#end of exit function
	syscall		