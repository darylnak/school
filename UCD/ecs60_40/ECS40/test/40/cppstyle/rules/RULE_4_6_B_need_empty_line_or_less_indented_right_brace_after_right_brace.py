"""
Need empty line or less indented right brace after right brace.

== Violation ==

    void Function() 
    {
      for (;;)  
      { 
        print("WOW"); 
      }                 
      if(x < 7)    <== Violation: Need empty line above
      {
        printf("OK);
      }
    }              <== Less indented right brace OK

== Good ==

    void Function() 
    {
      for (;;)  
      { 
        print("WOW"); 
      }                 

      if(x < 7)   
      {
        printf("OK);
      }
    }            

"""

from nsiqcppstyle_reporter import *
from nsiqcppstyle_checker import *
from nsiqcppstyle_rulemanager import *

def RunRule(lexer, contextStack) :
    t = lexer.GetCurToken()

    if t.type == "RBRACE" :
      nextToken2 = lexer.GetNextTokenSkipWhiteSpaceAndCommentAndPreprocess()
      if nextToken2.type not in ["RBRACE", "COMMA", "SEMI", "ELSE", "CATCH"] and nextToken2.lineno < t.lineno + 2 and not (nextToken2.type == "WHILE" and nextToken2.lineno == t.lineno) :
            nsiqcppstyle_reporter.Error(t, __name__, "need empty line or less indented right brace after right brace ")

ruleManager.AddFunctionScopeRule(RunRule)



###########################################################################################
# Unit Test
###########################################################################################

from nsiqunittest.nsiqcppstyle_unittestbase import *

class testRule(nct):
    def setUpRule(self):
        ruleManager.AddFunctionScopeRule(RunRule)   
    def test1(self):
        self.Analyze("thisfile.c","""
void function() {
for (;;) 
    a = 3;
}
""")
        assert CheckErrorContent(__name__)
    def test2(self):
        self.Analyze("thisfile.c","""
void function() {
for (;;)  {
    a = 3;
    }
}
""")
        assert not CheckErrorContent(__name__)
    def test3(self):
        self.Analyze("thisfile.c","""
void function() {
while(True)
    sdsd();
}
""")
        assert  CheckErrorContent(__name__)

    def test4(self):
        self.Analyze("thisfile.c","""
void function() {
do {
} while(true);
}
""")
        assert not CheckErrorContent(__name__)

    def test5(self):
        self.Analyze("thisfile.c","""
void function() {
if (true) {
    sdsd();
    } else 
        SSDD();
}
""")
        assert  CheckErrorContent(__name__)

    def test6(self):
        self.Analyze("thisfile.c","""
void function() {
if (true) {
    sdsd();
    } else {
        SSDD();
    } else if (true) {
    }
    
}
""")
        assert not CheckErrorContent(__name__)
