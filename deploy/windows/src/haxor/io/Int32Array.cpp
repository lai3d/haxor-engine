#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_Int32Array
#include <haxor/io/Int32Array.h>
#endif
namespace haxor{
namespace io{

Void Int32Array_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.Int32Array","new",0xac0b1c59,"haxor.io.Int32Array.new","haxor/io/Int32Array.hx",48,0xda7d9697)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(48)
	super::__construct(p_length);
}
;
	return null();
}

//Int32Array_obj::~Int32Array_obj() { }

Dynamic Int32Array_obj::__CreateEmpty() { return  new Int32Array_obj; }
hx::ObjectPtr< Int32Array_obj > Int32Array_obj::__new(int p_length)
{  hx::ObjectPtr< Int32Array_obj > result = new Int32Array_obj();
	result->__construct(p_length);
	return result;}

Dynamic Int32Array_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Int32Array_obj > result = new Int32Array_obj();
	result->__construct(inArgs[0]);
	return result;}

int Int32Array_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.Int32Array","get_bytesPerElement",0x3af8c4ba,"haxor.io.Int32Array.get_bytesPerElement","haxor/io/Int32Array.hx",40,0xda7d9697)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	return (int)4;
}


int Int32Array_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.Int32Array","Get",0xabed846f,"haxor.io.Int32Array.Get","haxor/io/Int32Array.hx",65,0xda7d9697)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(72)
	::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
	HX_STACK_LINE(73)
	int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(74)
	
		long v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p + 1];
		ptr[2] = (char) aux->b[p + 2];
		ptr[3] = (char) aux->b[p + 3];
		return v;
		;
	HX_STACK_LINE(83)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(Int32Array_obj,Get,return )

Void Int32Array_obj::Set( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.Int32Array","Set",0xabf69f7b,"haxor.io.Int32Array.Set","haxor/io/Int32Array.hx",97,0xda7d9697)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(104)
		::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
		HX_STACK_LINE(105)
		int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(106)
		
		long v   = p_value;
		char* ptr = (char*)(&v);
		aux->b[p]   = ptr[0];
		aux->b[p + 1] = ptr[1];		
		aux->b[p + 2] = ptr[2];		
		aux->b[p + 3] = ptr[3];				
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Int32Array_obj,Set,(void))

Void Int32Array_obj::SetRange( Array< int > p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.Int32Array","SetRange",0x9bdb7842,"haxor.io.Int32Array.SetRange","haxor/io/Int32Array.hx",128,0xda7d9697)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(128)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(128)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(128)
		while((true)){
			HX_STACK_LINE(128)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(128)
				break;
			}
			HX_STACK_LINE(128)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(128)
			this->Set((i + p_offset),p_data->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Int32Array_obj,SetRange,(void))

Void Int32Array_obj::SetViewSlice( int p_start,int p_length){
{
		HX_STACK_FRAME("haxor.io.Int32Array","SetViewSlice",0x2ab42cb2,"haxor.io.Int32Array.SetViewSlice","haxor/io/Int32Array.hx",138,0xda7d9697)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(138)
		this->super::SetViewSlice(p_start,p_length);
	}
return null();
}


::haxor::io::Int32Array Int32Array_obj::Alloc( Array< int > p_data){
	HX_STACK_FRAME("haxor.io.Int32Array","Alloc",0x35de108e,"haxor.io.Int32Array.Alloc","haxor/io/Int32Array.hx",22,0xda7d9697)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(23)
	::haxor::io::Int32Array b = ::haxor::io::Int32Array_obj::__new(p_data->length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(24)
	b->SetRange(p_data,null());
	HX_STACK_LINE(25)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int32Array_obj,Alloc,return )


Int32Array_obj::Int32Array_obj()
{
}

Dynamic Int32Array_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Alloc") ) { return Alloc_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetRange") ) { return SetRange_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SetViewSlice") ) { return SetViewSlice_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_bytesPerElement") ) { return get_bytesPerElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Int32Array_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Int32Array_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Alloc"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_bytesPerElement"),
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetRange"),
	HX_CSTRING("SetViewSlice"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Int32Array_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Int32Array_obj::__mClass,"__mClass");
};

#endif

Class Int32Array_obj::__mClass;

void Int32Array_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.Int32Array"), hx::TCanCast< Int32Array_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Int32Array_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io