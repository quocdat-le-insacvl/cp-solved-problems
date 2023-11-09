from builtins import pow
import pyperclip


def cprint(a):
	print(a)
	pyperclip.copy(a)


def main(inp, is_real):
	inp = inp.strip()
	inp = inp.split('\n')


samp_inp = r"""

"""

real_inp = r"""

"""

print("Sample:")
main(samp_inp, False)

print("Actual:")
main(real_inp, True)
