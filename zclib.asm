	.386p
	.mmx
	model flat

PUBLIC	@$bdele$qpv
PUBLIC	@__InitExceptBlockLDTC
PUBLIC	@$bdla$qpv
PUBLIC	@$bnwa$qui

EXTRN	malloc:near
EXTRN	free:near

_TEXT	segment dword public use32 'CODE'
@$bdele$qpv:
	push	eax
	call	free
	ret
@$bdla$qpv:
	push	eax
	call	free
	ret
@$bnwa$qui:
	push	eax
	call	malloc
	ret
@__InitExceptBlockLDTC:
	ret
_TEXT	ends
end

