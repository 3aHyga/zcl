	.386p
	model flat

PUBLIC	@Module$ggg
PUBLIC	@IntPower$ggi
PUBLIC	@Sqrt$gg
PUBLIC	@Exp$gg

_TEXT	segment dword public use32 'CODE'
@@Module$ggg	segment virtual
@Module$ggg	proc	near
	;in:
	;st(0): first value
	;st(1): second value
	;out
	;st(0): result value
	fmul	st(0), st(0)
	fxch
	fmul	st(0), st(0)
	faddp
	fsqrt
	ret
@Module$ggg	endp
@@Module$ggg	ends
;------------------------------------------------------------------------------
@@IntPower$ggi	segment virtual
@IntPower$ggi	proc	near
	;in:
	;st(0): value
	;eax: degree
	;out
	;st(0): result value
	ret
@IntPower$ggi	endp
@@IntPower$ggi	ends
;------------------------------------------------------------------------------
@@Sqrt$gg	segment virtual
@Sqrt$gg	proc	near
	;in:
	;st(0): first value
	;out
	;st(0): result value
	fsqrt
	ret
@Sqrt$gg	endp
@@Sqrt$gg	ends
;------------------------------------------------------------------------------
@@Exp$gg	segment virtual
@Exp$gg proc	near
	;in:
	;st(0): input value
	;out
	;st(0): result value
	ftst
	fstsw	ax
	sahf
	jnc	short @Exp$gg_1
	;change sign
	fchs
@Exp$gg_1:
	;calc x1 = x / ln 2
;	 fldln2
;	 fdivp
	fldl2e
	fmulp
	fld	st(0)
	pushfd
	push	eax
	fstcw	[esp]
	or	byte ptr[esp+1], 0ch
	;fclex
	fldcw	[esp]
	frndint ;set up rounding
	fsubr	st(0),st(1)
	f2xm1
	fld1
	faddp
	fscale
	pop	eax
	fnclex
	ffree	st(1)
	popfd
	jnc	short @Exp$gg_2
	;val = 1 / val
	fld1
	fdivrp
@Exp$gg_2:
	ret
@Exp$gg endp
@@Exp$gg	ends


;@__InitExceptBlockLDTC:
;	 ret
_TEXT	ends

	end

