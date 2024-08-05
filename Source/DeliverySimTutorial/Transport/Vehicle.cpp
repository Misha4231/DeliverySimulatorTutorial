#include "Vehicle.h"
#include "ChaosVehicleMovementComponent.h"

AVehicle::AVehicle() {
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(CameraBoom);
}

void AVehicle::BeginPlay() {
    Super::BeginPlay();

    
}

void AVehicle::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("LookRight", this, &AVehicle::LookRight);
    PlayerInputComponent->BindAxis("LookUp", this, &AVehicle::LookUp);

    PlayerInputComponent->BindAxis("MoveForward", this, &AVehicle::MoveForward);
    PlayerInputComponent->BindAxis("LurnLeft", this, &AVehicle::LurnLeft);
    PlayerInputComponent->BindAxis("MoveBack", this, &AVehicle::MoveBack);

    PlayerInputComponent->BindAction("HandBrake", EInputEvent::IE_Pressed, this, &AVehicle::StartHandBrake);
    PlayerInputComponent->BindAction("HandBrake", EInputEvent::IE_Released, this, &AVehicle::StopHandBrake);
}

void AVehicle::LookRight(const float Scale)
{
    AddControllerYawInput(Scale);
}

void AVehicle::LookUp(const float Scale)
{
    AddControllerPitchInput(Scale);
}

void AVehicle::MoveForward(const float Scale)
{
    GetVehicleMovementComponent()->SetThrottleInput(Scale);
}

void AVehicle::LurnLeft(const float Scale)
{
    GetVehicleMovementComponent()->SetSteeringInput(Scale);
}

void AVehicle::MoveBack(const float Scale)
{
    GetVehicleMovementComponent()->SetBrakeInput(-Scale);
}

void AVehicle::StartHandBrake()
{
    GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AVehicle::StopHandBrake()
{
    GetVehicleMovementComponent()->SetHandbrakeInput(false);
}
