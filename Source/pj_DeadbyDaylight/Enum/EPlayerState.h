UENUM(BlueprintType)
enum class EPlayerState : uint8 {
    Normal       UMETA(DisplayName="Normal"),
    Catch        UMETA(DisplayName="Catch"),
    Rooted        UMETA(DisplayName="Rooted"),
    Escaped        UMETA(DisplayName = "Escaped"),
    InSafeRoom        UMETA(DisplayName = "InSafeRoom"),
    Repairing        UMETA(DisplayName = "Repairing"),
    HitDown        UMETA(DisplayName = "HitDown"),
    Helping        UMETA(DisplayName = "Helping"),
    OnSacrifice        UMETA(DisplayName = "OnSacrifice"),
    Stun        UMETA(DisplayName = "Stun"),
    BreakingGenerator        UMETA(DisplayName = "BreakingGenerator"),
    PickingPeople   UMETA(DisplayName = "PickingPeople"),
    BeingHelped   UMETA(DisplayName = "BeingHelped"),
    OutOffBattle   UMETA(DisplayName = "OutOffBattle"),
    Skilling   UMETA(DisplayName = "Skilling"),
    Dead   UMETA(DisplayName = "Dead"),
};