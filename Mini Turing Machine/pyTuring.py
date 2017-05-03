#-*- coding: utf-8 -*-
import re

class TurError(Exception):
	def __init__(self, msg):
		self.msg = msg
	def __str__(self):
		return "규격에 맞지 않는 코드입니다. %s" % self.msg

def main():
	intListU = ''+input()
	intList = ''.join(intListU.split())
	TuringEnd = False
	PC = 0
	LabelDic = {}
	VarDic = {}
	alph = re.compile('[a-zA-Z]')
	for i in range(len(intList)):
		if intList[i] is ':':
			LabelDic[intList[i+1]] = i+2

	try:
		while TuringEnd is not True:
			if intList[PC] is ':':
				PC += 2
			elif intList[PC] is '=':
				VarDic[intList[PC+1]] = int(intList[PC+2])
				PC += 3
			elif intList[PC] is 'c':
				if VarDic[intList[PC+1]] is 0: PC = LabelDic[intList[PC+3]]
				else: PC = LabelDic[intList[PC+2]]
			elif intList[PC] is 'p':
				print(VarDic[intList[PC+1]])
				PC += 2
			elif intList[PC] is '+':
				if alph.match(intList[PC+2]):
					tmp = VarDic[intList[PC+2]]
				else: tmp = int(intList[PC+2])
				VarDic[intList[PC+1]] += tmp
				PC += 3
			elif intList[PC] is '-':
				if alph.match(intList[PC+2]):
					tmp = VarDic[intList[PC+2]]
				else: tmp = int(intList[PC+2])
				VarDic[intList[PC+1]] -= tmp
				PC += 3
			elif intList[PC] is '*':
				if alph.match(intList[PC+2]):
					tmp = VarDic[intList[PC+2]]
				else: tmp = int(intList[PC+2])
				VarDic[intList[PC+1]] *= tmp
				PC += 3
			elif intList[PC] is '/':
				if alph.match(intList[PC+2]):
					tmp = VarDic[intList[PC+2]]
				else: tmp = int(intList[PC+2])
				VarDic[intList[PC+1]] /= tmp
				PC += 3
			elif intList[PC] is ';': TuringEnd = True
			else: raise TurError("%d 번 명령에서 오류"%PC)
	except TurError as e:
		print(e)

if __name__ == '__main__': main()
