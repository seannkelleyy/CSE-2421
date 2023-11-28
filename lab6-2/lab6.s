# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
# THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
# THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
# INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY

.file "sum.s"

.section	.rodata.str1.1,"aMS",@progbits,1
PR_1:
	.string "\nSize of the array: %i\n"
Result:
	.string "\nThe sum is: %i"
	
PInt:
	.string "%i "
	
.data
.align 8
array:
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0

.globl sum
	.type	sum, @function
.text
sum:
	pushq %rbp		# stack frame management
	movq %rsp, %rbp	# stack frame management

	#pushing these to save their values 
	pushq %rdi # array
	pushq %rsi	# size of array

	# print array length
	movq $PR_1,%rdi	# move string into 
	movq $0,%rax # clear %rax for printf function
	call printf # printf to print array length
	popq %rsi # popping to get value back for size
	popq %rdi # popping to get value back for array

	movq %rdi, %rax  # move array pointer to %rax
    movq %rsi, %rcx  # move count to %rcx
    xorq %rdx, %rdx  # clear %rdx to hold the sum

	loop:
		cmpq $0, %rcx    # compare count with 0
		jle exit          # if count <= 0, jump to end
		addq (%rax), %rdx  # add current element to sum
		addq $8, %rax    # move to next element
		decq %rcx        # decrement count
    jmp loop         # jump to top of loop
	# get sum using loop

	exit: 
		movq $Result, %rdi  # move format string to %rdi
		movq %rdx, %rsi # move sum into rsi
		movq $0, %rax  # clear %rax for printf function
		call printf  # call printf to print the result

		leave # does stack frame management
		ret
.size sum,.-sum

