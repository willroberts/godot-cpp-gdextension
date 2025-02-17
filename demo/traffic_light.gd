extends TrafficLight


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass


func _get_next_light(current_light: TrafficLightType) -> TrafficLightType:
	if current_light == TrafficLightType.TRAFFIC_LIGHT_GO:
		return TrafficLightType.TRAFFIC_LIGHT_CAUTION
	elif current_light == TrafficLightType.TRAFFIC_LIGHT_CAUTION:
		return TrafficLightType.TRAFFIC_LIGHT_STOP
	elif current_light == TrafficLightType.TRAFFIC_LIGHT_STOP:
		return TrafficLightType.TRAFFIC_LIGHT_GO
	else:
		print('Unknown light type')
		return 0
