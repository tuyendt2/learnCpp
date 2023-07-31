#ifndef HEADER_H_
#define HEADER_H_

/**
 * A class defined without normal constructor, only copy-constructor defined
 */
class TestClass{
public:
	TestClass(const TestClass & other){
		m_IntValue = other.m_IntValue;
	}

	int getValue(){
		return m_IntValue;
	}
private:
	int m_IntValue;
};

#endif /* HEADER_H_ */
