import { Inject, Injectable, OnModuleInit } from '@nestjs/common';
import {
  ClientProxy,
  Ctx,
  MessagePattern,
  MqttContext,
  Payload,
} from '@nestjs/microservices';

@Injectable()
export class AppService implements OnModuleInit {
  constructor(@Inject('WEATHER_SERVICE') private weatherService: ClientProxy) {}
  onModuleInit() {
    console.log('Connect mqtt');
    this.weatherService.connect();
  }

  getHello(): string {
    return 'Hello World!';
  }

  
}
