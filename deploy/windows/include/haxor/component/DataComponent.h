#ifndef INCLUDED_haxor_component_DataComponent
#define INCLUDED_haxor_component_DataComponent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Component.h>
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,DataComponent)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  DataComponent_obj : public ::haxor::component::Component_obj{
	public:
		typedef ::haxor::component::Component_obj super;
		typedef DataComponent_obj OBJ_;
		DataComponent_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DataComponent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DataComponent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DataComponent"); }

		Dynamic data;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_DataComponent */ 