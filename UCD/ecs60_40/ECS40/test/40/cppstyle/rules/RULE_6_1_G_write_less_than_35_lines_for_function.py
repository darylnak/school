"""
Do not write more than 35 lines for a function.
It's really hard to detect comment line with keeping enough speed. 
So it only counts non blank line. 

== Violation ==

    void f() {
    -- more than 35 lines <== Violated
    }

== Good ==

    void f() {
    -- less than 35 lines <== OK
    }

"""

from nsiqcppstyle_rulehelper import  *
from nsiqcppstyle_reporter import *
from nsiqcppstyle_rulemanager import *


def RunRule(lexer, fullName, decl, contextStack, context) :
    if not decl and context != None :
        switchFound = 0
        startline = context.startToken.lineno
        endline = context.endToken.lineno

        for eachLine in lexer.lines[startline-1:endline-1] :
          if "switch" in eachLine :
            switchFound = 1 
#            if not Match("^\s*$", eachLine) :
#                count += 1
        if endline - startline > 36 and switchFound == 0 :
            nsiqcppstyle_reporter.Error(context.startToken, __name__, "Do not write function over 35 lines(%s)." % fullName)

ruleManager.AddFunctionNameRule(RunRule)

###########################################################################################
# Unit Test
###########################################################################################


from nsiqunittest.nsiqcppstyle_unittestbase import *
class testRule(nct):
    def setUpRule(self):
        ruleManager.AddFunctionNameRule(RunRule)   
    def test1(self):
        self.Analyze("thisfile.c","int k() {%s};" % ("hello\n\n"*36))
        assert CheckErrorContent(__name__)
    def test2(self):
        self.Analyze("thisfile.c", "int k() {%s};" % ("hello\n\n"*25))
        assert not CheckErrorContent(__name__)
    def test3(self):
        self.Analyze("thisfile.c", "int k() {%s};" % ("hello\n\n"*35))
        assert not CheckErrorContent(__name__)
