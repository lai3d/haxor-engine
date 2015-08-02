#if html

package ;
import js.html.EventTarget;
import haxor.platform.html.input.DragDrop;
import haxe.io.UInt8Array;
import js.html.Uint8Array;
import js.html.ArrayBuffer;
import js.html.FileReader;
import js.html.File;
import js.html.Event;
import haxe.Timer;
import haxor.component.animation.Animation;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.MeshRenderer;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Entity;
import haxor.core.Enums.AnimationWrap;
import haxor.core.Enums.CameraMode;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.ForceMode;
import haxor.core.Enums.InputState;
import haxor.core.IFixedUpdateable;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.RenderStats;
import haxor.core.Time;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.ds.SAP;
import haxor.ds.USet;
import haxor.graphics.Gizmo;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout;
import haxor.graphics.mesh.Model;
import haxor.graphics.Screen;
import haxor.graphics.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.input.Input;
import haxor.input.Joystick;
import haxor.input.KeyCode;
import haxor.io.Buffer;
import haxor.io.file.ColladaFile;
import haxor.io.file.MaterialFile;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Random;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.net.Web;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext.GraphicAPI;
import haxor.physics.broadphase.SAPBroadPhase;
import haxor.physics.Collision;
import haxor.physics.Physics;
import haxor.physics.PhysicsMaterial;
import haxor.platform.html.graphics.ImageReader;
import haxor.platform.Types.Float32;
import haxor.platform.Types.MeshBufferId;
import haxor.thread.Activity;
import js.Browser;

class MainHTML extends Application implements IRenderable
{	
	static public function main():Void {  EntryPoint.Initialize(); }
	
	override public function Initialize():Void 
	{
		Console.Log(platform + "> Application Initialize");
		
		var sphere : MeshRenderer = (new Entity("sphere")).AddComponent(MeshRenderer);
		sphere.mesh = Model.sphere;
		sphere.material = Material.Transparent(Texture2D.green);
		sphere.material.SetColor("Tint", Color.white);
		
		var o : CameraOrbit = CameraOrbit.Create(4.0, 45, 45);				
		o.camera.background = new Color(0.3, 0.3, 0.3);			
		var ci : CameraOrbitInput = o.AddComponent(CameraOrbitInput);
		
		
		DragDrop.Add(Browser.window);
		
		DragDrop.AddListener(function(t : EventTarget, evt : String, ev:Event):Void
		{
			trace(t,evt);			
			if (evt == "drop")
			{
				
				var data : Dynamic = ev;
				data = data.dataTransfer;
				var files : Array<File> = data == null ? [] : data.files;							
				var reader = new FileReader();
				reader.onerror = function(ev:Dynamic):Void { trace(ev); }				
				reader.onloadend = function(ev : Dynamic):Void
				{	
					
					var ab : Uint8Array = new Uint8Array(ev.target.result);
					var b : Buffer = new Buffer(ab.byteLength);
					b.buffer.set(ab);						
					ImageReader.ReadAsync(b, function(img:Bitmap):Void
					{
						var tex : Texture2D = Texture2D.FromBitmap(img);
						sphere.material.SetTexture("DiffuseTexture", tex);
					});				
					//*/
				};							
				reader.readAsArrayBuffer(files[0]);				
			}
		});
		
	}
	
	public function OnRender():Void
	{
		Gizmo.Grid(100.0);
	}
}

#end