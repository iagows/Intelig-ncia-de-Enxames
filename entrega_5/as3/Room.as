package
{
	import flash.display.Sprite;
	import Person;

	public class Room extends Sprite
	{
		public function Room()
		{
			this.image();
		}

		private function image():void
		{
			this.graphics.clear();
			this.graphics.lineStyle(1);
			this.graphics.drawRect(0,0, 200, 200);
		}

		public function addPerson(p:Person):void
		{
			this.addChild(p);
		}

		public function clear():void
		{
			while(this.numChildren>0)
				this.removeChildAt(0);
		}
	}
}