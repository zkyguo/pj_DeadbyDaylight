UENUM(BlueprintType)
enum class EGameItemType : uint8 {
    None       UMETA(DisplayName="None"),
    Generator UMETA(DisplayName = "Generator"),
    Cross UMETA(DisplayName = "Cross"),
    Door UMETA(DisplayName = "Door "),
    Shop UMETA(DisplayName = "Shop"),
    HitDownExorcist UMETA(DisplayName = "HitDown"),
};