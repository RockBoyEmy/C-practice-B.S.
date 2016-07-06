//the calculator - final version directly (probably)
#include "std_lib_facilities.h"

const char number = '8';	//t.kind==number means that t is a number token
const char quit = 'q';		//t.kind==quit means that t is a quit Token
const char print = ';';		//t.kind==print means that t is a print Token
const string prompt = ">";
const string result = "=";	//used to indicate that what follows is a result

class Token {
public:
	char kind;		//what kind of token
	double value;	//for numbers: a value
	Token(char ch)	//make a Token from a char
		:kind(ch), value(0) {}
	Token(char ch, double val)	//make a Token from a char and a double
		:kind(ch), value(val) {}
};
class Token_stream {
public:
	Token_stream();			//make a Token_stream that reads from cin
	Token get();			//get a Token
	void putback(Token t);	//put a Token back
	void ignore(char c);	//discard characters up to and including c

private:
	bool full;		//is there a Token in the buffer?
	Token buffer;	//here is where we keep a Token put back using putback()
};

Token_stream::Token_stream()
	:full(false), buffer(0) {
}
Token Token_stream::get()
	//read characters from cin and compose a Token
{
	if (full) { //check if we already have a Token ready
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch; //note that >> skips whitespace

	switch (ch)
	{
	case print:
	case quit:
	case '(': 
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/':
		return Token(ch);	//let each character represent itself
	case '.':				//a floating-point-literal can start with a dot
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);		//put digit back into the input stream
		double val;
		cin >> val;				//read a floating-point number (the compiler knows it's a numeric value)
		return Token(number, val);
	}
	default:
		error("Bad token");
	}
}
void Token_stream::putback(Token t)
{
	if (full)
	{
		error("putback() into a full buffer");
	}
	buffer = t;		//copy t to buffer
	full = true;	//buffer is now full
}
void Token_stream::ignore(char c)
	//c represents the Token kind
{
	//first look in buffer
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	//now search input
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

Token_stream ts;		//provides get() and putback()
double expression();	//declaration so that primary() can call expression()

void clean_up_mess()
{
	ts.ignore(print);
}
double primary() {
	Token t = ts.get(); //aici era inainte doar get_token()
	switch (t.kind)
	{
	case '(':	//handle '(' espression ')'
		{
			double d = expression();
			t = ts.get(); //la fel si aici
			if (t.kind != ')')
			{
				error("')' expected");
			}
			return d;
		}
	case number:
		return t.value;		//return the number's value
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("primary expected");
	}
}
double term()
{
	double left = primary();
	Token t = ts.get();		//get the next Token from the Token stream

	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			{
				double d = primary();
				if (d == 0)
				{
					error("divide by 0");
				}
				left /= d;
				t = ts.get();
				break;
			}
		case '%':
		{
			double d = primary();
			int i1 = int(left);
			if (i1 != left) error("left-hand operand of % not int");
			int i2 = int(d);
			if(i2 != d) error("right-hand operand of % not int");
			if (i2 == 0) error("%: divide by zero");
			left = i1%i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);	//pu back t into the Token stream
			return left;
		}
	}
}
double expression()
{
	double left = term();	//read and evaluate a Term
	Token t = ts.get();		//get the next Token from the Token stream

	while(true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();	//evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term(); //evaluate Term and substract
			t = ts.get();
			break;
		default:
			ts.putback(t);	//put t back into the token stream
			return left;	//finally: no more + or -; return the answer
		}
	}
}
void calculate()		//expression evaluation loop
{
	while (cin)
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();	//first discard all "prints"
		if (t.kind == quit)	return;
		ts.putback(t);
		cout << result << expression() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;	//write error message
		clean_up_mess();
	}
}

int main()
try {
	calculate();
	keep_window_open();	//cope with Windows console mode
	return 0;
}
catch (exception& e)
{
	cerr << e.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	keep_window_open("~~");
	return 2;
}
