package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Enums.TextureType;
import haxor.math.Color;

/**
 * Class that represents a 2D texture.
 * @author Eduardo Pons
 */
class Texture2D extends Texture
{	
	/**
	 * Template texture with a single white pixel.
	 */
	static public var white(get_white, never):Texture2D;
	static private function get_white():Texture2D
	{
		if (m_white != null) return m_white;
		m_white = new Texture2D(1, 1, PixelFormat.RGB8);
		m_white.data.Fill(Color.white);
		m_white.Apply();
		return m_white;
	}
	static private var m_white : Texture2D;
	
	/**
	 * Template texture with a single red pixel.
	 */
	static public var red(get_red, never):Texture2D;
	static private function get_red():Texture2D
	{
		if (m_red != null) return m_red;
		m_red = new Texture2D(1, 1, PixelFormat.RGB8);
		m_red.data.Fill(Color.red);
		m_red.Apply();
		return m_red;
	}
	static private var m_red : Texture2D;
	
	/**
	 * Creates a new Texture2D from a bitmap reference.
	 * The pixels are all set but the user must choose if the texture will automatically applied or wait for the best moment to Apply or Upload.
	 * @param	p_bitmap
	 * @return
	 */
	static public function FromBitmap(p_bitmap : Bitmap,p_apply:Bool=true):Texture2D
	{
		var t : Texture2D = new Texture2D(0, 0, p_bitmap.format);
		t.m_data 	= p_bitmap;
		t.m_width 	= p_bitmap.width;
		t.m_height 	= p_bitmap.height;
		EngineContext.texture.Create(t);		
		t.Apply();
		return t;
	}
	
	/**
	 * Reference to the bitmap which contains the pixels for this Texture.
	 */
	public var data(get_data, null):Bitmap;
	private inline function get_data():Bitmap { return m_data; }
	private var m_data : Bitmap;
	
	/**
	 * Returns the enum for this texture type.
	 * @return
	 */
	override inline function get_type():TextureType { return TextureType.Texture2D; }
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : PixelFormat)
	{
		super();
		m_format = p_format;
		m_width  = p_width;
		m_height = p_height;
		if (p_width <= 0)  return;
		if (p_height <= 0) return;
		m_data 	 = new Bitmap(p_width, p_height, p_format);
		EngineContext.texture.Create(this);
	}
	
	/**
	 * Sends the pixels of this texture in async mode.
	 * It is possible to tell the speed of the upload by the number of steps before finishing the task.
	 * @param	p_on_complete
	 */
	public function Upload(p_steps : Int=200,p_on_complete:Void->Void=null):Void
	{
		EngineContext.texture.UploadTexture(this, p_steps,p_on_complete);
	}
	
}