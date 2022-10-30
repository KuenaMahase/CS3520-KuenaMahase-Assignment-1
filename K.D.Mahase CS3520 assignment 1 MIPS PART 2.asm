# Kuena Mahase 202000020 
# number: 59598785/69426317
#email: kuenamahase1101@gmail.com
#CS2520 Assignment 1

.data

.text

main:
	jal pRIMENUMBER    	#calling the prime function
	li $v0, 1		#outputing the result of the prime function	
	add $a0,$t2,0
	syscall
	
	li $v0, 10		#End of main function
	syscall	
	
	pRIMENUMBER:
		li $a1,3500	#a1 = 3500
		li $t1,0	#t1 = 0
		
		
	ForLoop1:

		bgt $t1,$a1,Exit	#branch if t1 > a1 to exit
		bgt $t1,1,ForLoop2	#branch if t1 >1 to ForLoop2
		
		addi $t1,$t1,1		# t1 = t1 + 1
		
		j ForLoop1		#for ForLoop1 to loop again
		jr $ra
		
	ForLoop2:
		li $t2,2		#li t2 = 2
		div $a1,$t2		# a1/t2
		mflo $t3		# t3 = a1/t2 (a1/2)
		bgt $t2,$t3,Exit	# if t2 > t3, branch to Exit
		
		div $t1,$t2		# t1/t2
		mfhi $t4		# move the remainder of t1/t2 to t4
		beq $t4,$zero,Exit	# if t4 = 0, branch to exit
		
		jal Prime		# calling prime function
		
		addi $t2,$t2,1		# t2 = t2 + 1
		
		j ForLoop2		# ForLoop2 to loop again
		jr $ra	
		
	Prime:
		li $v0, 1		#output prime integers
		addi $a0,$t2,0
		syscall	 
		
		jr $ra	
			
	Exit:
		li $v0, 1		
		add $a0,$t2,0
		syscall
		
		li $v0, 10		#end of exit function
		syscall										
