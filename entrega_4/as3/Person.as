package
{
	import flash.display.Sprite;
	
	public class Person extends Sprite
	{
		private var infinite:Boolean;
		public function Person(c:String)//se for Aerosol, é infinito
		{
			this.infinite = c == "a" ? true : false;
			this.image();
		}

		private function image():void
		{
			this.graphics.clear();
				this.graphics.beginFill(0xff0000);
			if(this.infinite)
			{
				this.graphics.drawCircle(0,0, 200);
			}
			else
			{
				this.graphics.drawCircle(0,0, 10);
			}
			this.graphics.endFill();
			this.alpha = 0.07;
		}
	}
}