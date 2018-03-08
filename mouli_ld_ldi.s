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
	#ld %4, r3
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
	aff r2
	and r2, %0,r3
	aff r3
