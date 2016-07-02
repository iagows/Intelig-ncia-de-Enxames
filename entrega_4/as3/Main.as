package
{
	import flash.display.Sprite;
	import flash.events.Event;
	import Room;
	import Person;
	import Reader;
	import flash.text.TextField;

	[SWF(backgroundColor="0x000000", width="200", height="200", frameRate="1", pageTitle="IntEnx")]

	public class Main extends Sprite
	{
		private var array:Array;
		private var room:Room;
		private var counter:int=0;
		private var displayTxt:TextField = new TextField();
		
		public function Main()
		{
			room = new Room();
			this.addChild(room);
			addChild(displayTxt);
			
			var reader:Reader = new Reader();
			this.array = reader.getArray();

			this.addEventListener(Event.ADDED_TO_STAGE, added);
		}

		private function added(e:Event):void
		{
			this.removeEventListener(Event.ADDED_TO_STAGE, added);
			this.addEventListener(Event.ENTER_FRAME, frame);
		}

		private function frame(e:Event):void
		{
			this.room.clear();
			if(this.counter>this.array.length-1)
			{
				this.counter = 0;
			}
			var line0:Array = array[counter];
			for(var i:int=0; i<line0.length; i++)
			{
				var person:Person = line0[i];
				room.addPerson(person);
			}
			this.displayTxt.text = "It: "+counter + "000 : 10.000";
			counter++;
		}
	}
}