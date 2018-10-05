"""
Empty line, less indented control, or less indented right brace before control statement.

== Violation ==

    void Function() 
    {
      int i;
      for (;;)   <== Violation:  Need empty line above
        print("WOW"); 
            
      if(x < 7)
      {
        printf("OK);
      }
      while(i > 7)  <== Violation:Need empty line above
        i++; 
    }

== Good ==

    void Function() 
    {
      if(x > 12)  <== OK because of right brace less indented
        x++;

      for (;;)  
        if(x > 12) <== OK becaue control statement is less indented
          print("WOW"); 
            
      if(x < 7)
      {
        printf("OK);
      }

      while(i > 7) 
        i++; 
    }

"""

from nsiqcppstyle_reporter import *
from nsiqcppstyle_checker import *
from nsiqcppstyle_rulemanager import *

def RunRule(lexer, contextStack) :
    t = lexer.GetCurToken()
    prevToken = lexer.GetPrevToken()
    prevToken2 = lexer.GetPrevTokenSkipWhiteSpaceAndCommentAndPreprocess()

    if t.type in ("IF", "FOR", "DO", "SWITCH", "WHILE", "TRY") and not(prevToken2.type == "RBRACE" and prevToken2.lineno == t.lineno) :
        OK = 0

        if t.type == "IF" and prevToken2.type == "ELSE" and prevToken2.lineno + 1 <= t.lineno :
            OK = 1
        if prevToken2.type in ("IF", "FOR", "WHILE", "ELSE", "LBRACE", "COLON" ) and prevToken2.column + 2 == t.column :
            OK = 1
        if prevToken2.type == "RPAREN" : # End of a control statment on previous line 
            OK = 1
        if prevToken.type == "SPACE" and prevToken2.lineno + 2 <= t.lineno :
            OK = 1
        if prevToken2.type == "COLON" and prevToken2.lineno + 1 == t.lineno :
            OK = 1

        if not OK :
            nsiqcppstyle_reporter.Error(t, __name__, "need empty line, less indented control, or less indented right brace above control statement")
            print t.type, prevToken2.type, prevToken.type, prevToken2.column, t.column

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
