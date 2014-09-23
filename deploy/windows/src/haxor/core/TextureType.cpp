#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_TextureType
#include <haxor/core/TextureType.h>
#endif
namespace haxor{
namespace core{

::haxor::core::TextureType TextureType_obj::Compute;

::haxor::core::TextureType TextureType_obj::None;

::haxor::core::TextureType TextureType_obj::RenderTexture;

::haxor::core::TextureType TextureType_obj::Texture2D;

::haxor::core::TextureType TextureType_obj::TextureCube;

HX_DEFINE_CREATE_ENUM(TextureType_obj)

int TextureType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Compute")) return 4;
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("RenderTexture")) return 3;
	if (inName==HX_CSTRING("Texture2D")) return 1;
	if (inName==HX_CSTRING("TextureCube")) return 2;
	return super::__FindIndex(inName);
}

int TextureType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Compute")) return 0;
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("RenderTexture")) return 0;
	if (inName==HX_CSTRING("Texture2D")) return 0;
	if (inName==HX_CSTRING("TextureCube")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextureType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Compute")) return Compute;
	if (inName==HX_CSTRING("None")) return None;
	if (inName==HX_CSTRING("RenderTexture")) return RenderTexture;
	if (inName==HX_CSTRING("Texture2D")) return Texture2D;
	if (inName==HX_CSTRING("TextureCube")) return TextureCube;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("Texture2D"),
	HX_CSTRING("TextureCube"),
	HX_CSTRING("RenderTexture"),
	HX_CSTRING("Compute"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureType_obj::Compute,"Compute");
	HX_MARK_MEMBER_NAME(TextureType_obj::None,"None");
	HX_MARK_MEMBER_NAME(TextureType_obj::RenderTexture,"RenderTexture");
	HX_MARK_MEMBER_NAME(TextureType_obj::Texture2D,"Texture2D");
	HX_MARK_MEMBER_NAME(TextureType_obj::TextureCube,"TextureCube");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextureType_obj::Compute,"Compute");
	HX_VISIT_MEMBER_NAME(TextureType_obj::None,"None");
	HX_VISIT_MEMBER_NAME(TextureType_obj::RenderTexture,"RenderTexture");
	HX_VISIT_MEMBER_NAME(TextureType_obj::Texture2D,"Texture2D");
	HX_VISIT_MEMBER_NAME(TextureType_obj::TextureCube,"TextureCube");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class TextureType_obj::__mClass;

Dynamic __Create_TextureType_obj() { return new TextureType_obj; }

void TextureType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.TextureType"), hx::TCanCast< TextureType_obj >,sStaticFields,sMemberFields,
	&__Create_TextureType_obj, &__Create,
	&super::__SGetClass(), &CreateTextureType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void TextureType_obj::__boot()
{
hx::Static(Compute) = hx::CreateEnum< TextureType_obj >(HX_CSTRING("Compute"),4);
hx::Static(None) = hx::CreateEnum< TextureType_obj >(HX_CSTRING("None"),0);
hx::Static(RenderTexture) = hx::CreateEnum< TextureType_obj >(HX_CSTRING("RenderTexture"),3);
hx::Static(Texture2D) = hx::CreateEnum< TextureType_obj >(HX_CSTRING("Texture2D"),1);
hx::Static(TextureCube) = hx::CreateEnum< TextureType_obj >(HX_CSTRING("TextureCube"),2);
}


} // end namespace haxor
} // end namespace core