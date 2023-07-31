class FirstElement{
public:
	FirstElement(){}
};

class SecondElement{
public:
	SecondElement(){}
};

template < class T, class U>
class ParamClass{
	public:
	ParamClass(T t1, U u1){
		t = t1;
		u = u1;
	}
	T t;
	U u;
};

template < class T, class U, template <class T1, class U1> class V>
class TemplateClass {
public:
	TemplateClass(T t, U u){
		m_Instance = new V<T,U>(t,u);
	}

	V<T,U>* getInstance()
	{
		return m_Instance;
	}
private:
	V<T,U> *m_Instance;
};
