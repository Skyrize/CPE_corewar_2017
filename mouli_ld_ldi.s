.name		"test | ld - ldi"
.comment	"batterie de test pour ld et ldi (nécessite live et aff pour fonctionner)"

	#----- TEST LD INDIRECT -----
	#ld 6, r3
	#live %42
	#aff r3

	#----- TEST LD DIRECT -----
	#ld %42, r3
	#live %42
	#aff r3

	#----- TEST LDI REGISTER | REGISTER -----
	#ld %3, r2
	#ld %3, r3
	#ldi r2, r3, r4
	#live %42
	#aff r4

	#----- TEST LDI DIRECT | REGISTER -----
	#ld %4, r3xœ
	#ldi %3, r3, r4
	#live %42
	#aff r4

	#----- TEST LDI REGISTER | DIRECT -----
	#ld %4, r3
	#ldi r3, %3, r4
	#live %42
	#aff r4

	#----- TEST LDI DIRECT | DIRECT -----
	#ldi %4, %4, r4
	#live %42
	#aff r4

	#----- TEST LDI INDIRECT | DIRECT -----
	#ldi 13, %2, r4
	#live %42
	#live %6
	#aff r4

	#----- TEST LDI INDIRECT | REGISTER -----
	#ld %2, r2
	#ldi 12, r2, r4
	#live %42
	#live %5
	#aff r4

	#----- TEST LIVE -----#
	#live %1
	#live %4

	#----- TEST AND ------#
	#ld %42, r2
	#and r2, %42, r3
	#live %42
	#aff r3

	#----- TEST OR ------#
	#ld %0, r2
	#or %42, r2, r3
	#live %42
	#aff r3

	#----- TEST XOR ------#
	#ld %42, r2
	#and %42, %42, r3
	#live %42
	#aff r3

	#----- TEST ADD ------#
	#ld %21, r1
	#add r1, r1, r3
	#live %42
	#aff r3

	#----- TEST SUB ------#
	#ld %21, r1
	#sub r1, r1, r3
	#live %42
	#aff r3

	#----- TEST STI ------#
	#ld %42, r2
	#sti r2, %42, %42
	#live %42

	#----- TEST STI ------#
	#ld %42, r2
	#sti r2, %42, %42
	#live %42


	##########################


	#----- TEST STI REGISTER | REGISTER | REGISTER -----
	#ld %2, r2
	#ld %4, r3
	#sti r1, r2, r3
	#live %42

	#----- TEST STI REGISTER | REGISTER | DIRECT -----
	#ld %3, r2
	#sti r1, r2, %4
	#live %42

	#----- TEST STI REGISTER | DIRECT | REGISTER -----
	ld %3, r2
	sti r1, %4, r2
	live %3
	live %42

	#----- TEST STI REGISTER | DIRECT | DIRECT -----
	sti r1, %6, %2
	live %42

	#----- TEST STI REGISTER | INDIRECT | REGISTER -----
	ld %7, r2
	sti r1, 7, r2
	live %5
	live %42

	#----- TEST STI REGISTER | INDIRECT | DIRECT -----
	sti r1, 8, %8
	live %5
	live %42
	live %1
	live %2