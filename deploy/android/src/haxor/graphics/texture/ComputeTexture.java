package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ComputeTexture extends haxor.graphics.texture.Texture2D
{
	public    ComputeTexture(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    ComputeTexture(int p_width, int p_height, haxor.core.PixelFormat p_format)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.graphics.texture.ComputeTexture.__hx_ctor_haxor_graphics_texture_ComputeTexture(this, p_width, p_height, p_format);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_ComputeTexture(haxor.graphics.texture.ComputeTexture __temp_me255478, int p_width, int p_height, haxor.core.PixelFormat p_format)
	{
		haxor.graphics.texture.Texture2D.__hx_ctor_haxor_graphics_texture_Texture2D(__temp_me255478, p_width, p_height, p_format);
		__temp_me255478.set_minFilter(haxor.core.TextureFilter.Nearest);
		__temp_me255478.set_magFilter(haxor.core.TextureFilter.Nearest);
		__temp_me255478.m_lock = false;
		__temp_me255478.m_dirty = false;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.ComputeTexture(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.ComputeTexture(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((haxor.core.PixelFormat) (arr.__get(2)) ));
	}
	
	
	public  boolean m_lock;
	
	public  boolean m_dirty;
	
	@Override public   haxor.core.TextureType get_type()
	{
		return haxor.core.TextureType.Compute;
	}
	
	
	public final   void Write(int p_x, int p_y, java.lang.Object p_v0, java.lang.Object p_v1, java.lang.Object p_v2, java.lang.Object p_v3)
	{
		java.lang.Object __temp_p_v3255473 = ( (( p_v3 == null )) ? (((java.lang.Object) (0) )) : (((java.lang.Object) (p_v3) )) );
		java.lang.Object __temp_p_v2255472 = ( (( p_v2 == null )) ? (((java.lang.Object) (0) )) : (((java.lang.Object) (p_v2) )) );
		java.lang.Object __temp_p_v1255471 = ( (( p_v1 == null )) ? (((java.lang.Object) (0) )) : (((java.lang.Object) (p_v1) )) );
		java.lang.Object __temp_p_v0255470 = ( (( p_v0 == null )) ? (((java.lang.Object) (0) )) : (((java.lang.Object) (p_v0) )) );
		haxor.math.Color __temp_stmt256188 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256188 = _this.m_c.__get(_this.m_nc = ( (( _this.m_nc + 1 )) % _this.m_c.length ));
		}
		
		this.m_data.SetPixel(p_x, p_y, __temp_stmt256188.Set(__temp_p_v0255470, __temp_p_v1255471, __temp_p_v2255472, __temp_p_v3255473));
		this.m_dirty = true;
		this.Invalidate();
	}
	
	
	public   void WriteRange(haxe.root.Array<java.lang.Object> p_values, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_width, java.lang.Object p_height)
	{
		int __temp_p_height255477 = ( (( p_height == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_height)) )) );
		int __temp_p_width255476 = ( (( p_width == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_width)) )) );
		int __temp_p_y255475 = ( (( p_y == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_y)) )) );
		int __temp_p_x255474 = ( (( p_x == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_x)) )) );
		int w = 0;
		if (( __temp_p_width255476 < 0 )) 
		{
			w = this.m_width;
		}
		 else 
		{
			w = __temp_p_width255476;
		}
		
		int h = 0;
		if (( __temp_p_height255477 < 0 )) 
		{
			h = this.m_height;
		}
		 else 
		{
			h = __temp_p_height255477;
		}
		
		this.m_data.SetRange(__temp_p_x255474, __temp_p_y255475, w, h, p_values, null);
		this.Invalidate();
		this.m_dirty = true;
	}
	
	
	public   void Invalidate()
	{
		this.Apply();
	}
	
	
	public   void OnUploadComplete()
	{
		this.m_lock = false;
		if (this.m_dirty) 
		{
			this.Invalidate();
		}
		
		this.m_dirty = false;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256189 = true;
			switch (field.hashCode())
			{
				case 769016192:
				{
					if (field.equals("m_dirty")) 
					{
						__temp_executeDef256189 = false;
						this.m_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083328067:
				{
					if (field.equals("m_lock")) 
					{
						__temp_executeDef256189 = false;
						this.m_lock = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256189) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256190 = true;
			switch (field.hashCode())
			{
				case -1190396359:
				{
					if (field.equals("OnUploadComplete")) 
					{
						__temp_executeDef256190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUploadComplete"))) );
					}
					
					break;
				}
				
				
				case -1083328067:
				{
					if (field.equals("m_lock")) 
					{
						__temp_executeDef256190 = false;
						return this.m_lock;
					}
					
					break;
				}
				
				
				case 161615195:
				{
					if (field.equals("Invalidate")) 
					{
						__temp_executeDef256190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Invalidate"))) );
					}
					
					break;
				}
				
				
				case 769016192:
				{
					if (field.equals("m_dirty")) 
					{
						__temp_executeDef256190 = false;
						return this.m_dirty;
					}
					
					break;
				}
				
				
				case 1344790718:
				{
					if (field.equals("WriteRange")) 
					{
						__temp_executeDef256190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("WriteRange"))) );
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef256190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 83847103:
				{
					if (field.equals("Write")) 
					{
						__temp_executeDef256190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Write"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256190) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef256191 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef256191 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 83847103:
				{
					if (field.equals("Write")) 
					{
						__temp_executeDef256191 = false;
						this.Write(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5));
					}
					
					break;
				}
				
				
				case -1190396359:
				{
					if (field.equals("OnUploadComplete")) 
					{
						__temp_executeDef256191 = false;
						this.OnUploadComplete();
					}
					
					break;
				}
				
				
				case 1344790718:
				{
					if (field.equals("WriteRange")) 
					{
						__temp_executeDef256191 = false;
						this.WriteRange(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4));
					}
					
					break;
				}
				
				
				case 161615195:
				{
					if (field.equals("Invalidate")) 
					{
						__temp_executeDef256191 = false;
						this.Invalidate();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256191) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_dirty");
		baseArr.push("m_lock");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}

